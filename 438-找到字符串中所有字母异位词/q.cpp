#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> resdx;
        if (s==p) {
            resdx.push_back(0);
            return resdx; 
        }
        if (p.length()==1) {
            for (int i=0;i<s.length();i++) {
                if (s[i] == p[0]) resdx.push_back(i);
            }
            return resdx;
        }
        if(p.length() > s.length()) return resdx;

        unordered_map<char, int> charmap;
        for (int i=0;i<p.length();i++) {
            charmap[p[i]] += 1;
        }

        for (int i=0;i<s.length()-p.length()+1;i++) {
            if (charmap[s[i]]) {
                unordered_map<char, int> tmpmap = charmap;
                int suit = 1;
                for (int j=i;j<i+p.length();j++) {
                    tmpmap[s[j]] -= 1;
                    if (charmap[s[j]]) {
                        i=j;
                        suit = 0;
                        break;
                    }
                    if (tmpmap[s[j]]<0) {
                        suit = 0;
                        break;
                    }
                }
                if (suit) resdx.push_back(i);
            }
        }
        return resdx;
    }
};