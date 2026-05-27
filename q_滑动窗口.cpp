#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> resdx;
        
        // 边界判断
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

        vector<int> charp(26, 0), chars(26, 0);
        int ldx=0, rdx=p.length()-1;
        for (int i=0;i<p.length();i++) {
            charp[(int)(p[i]-'a')] += 1;
            chars[(int)(s[i]-'a')] += 1;
        }
        if (charp == chars) resdx.push_back(0);

        for (int i=1;i+rdx<s.length();i++) {
            chars[(int)(s[ldx+i-1]-'a')] -= 1;
            chars[(int)(s[rdx+i]-'a')] += 1;
            if (charp == chars) resdx.push_back(i); 
        }
        
        return resdx;
    }
};