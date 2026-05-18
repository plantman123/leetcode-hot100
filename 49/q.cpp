#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>


using namespace std;

class Solution {
public:
    static bool cmp (char a, char b){
        return (a<b);
    }

    static string get_key(string str) {
        std::sort(str.begin(), str.end(), cmp);
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> keys;
        map<string, vector<string>> str_map;
        for (int i=0;i<strs.size();i++) {
            string stri = strs[i];
            string str_key = get_key(stri);
            if (!str_map[str_key].size()) {
                keys.push_back(str_key);
            }
            str_map[str_key].push_back(stri);
        }

        vector<vector<string>> results(keys.size());
        for (int i=0;i<keys.size();i++) {
            for (int j=0;j<str_map[keys[i]].size();j++) {
                results[i].push_back(str_map[keys[i]][j]);
            }
        }

        return results;
    }
};