#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    static int max2(int a, int b) {
        if (a > b) return a;
        return b;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) {return s.length();}

        int resl = 1;
        s = 'a' + s;
        for (int i=1;i<s.length()-1;) {
            if (s[i] != s[i+1]) {
                cout << s[i] << endl;
                unordered_map<char, int> chardx;
                chardx[s[i]] = i;
                chardx[s[i+1]] = i+1;
                int new_resl = 2;
                resl = max2(resl, new_resl);
                for (int j=i+2;j<s.length();j++) {
                    if (chardx[s[j]]) {
                        resl = max2(resl, new_resl);
                        i = chardx[s[j]];
                        break;
                    }
                    if (j == s.length()-1) {
                        resl = max2(resl, new_resl+1);
                        return resl;
                    }
                    chardx[s[j]] = j;
                    new_resl += 1;
                }
            }
            i += 1;
        }

        return resl;
    }
};