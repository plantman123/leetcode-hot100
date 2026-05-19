#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        long base = 1000000000;
        unordered_map<long, int> num_map;
        unordered_set<long> num_set;
        for (int i=0;i<nums.size();i++) {
            // num_map[nums[i]] = 1;
            num_set.insert(nums[i]);
        }

        long max_length = 0;
        for (int i=0;i<nums.size();i++) {
            // if (num_map[nums[i]-1]) continue;
            if (num_set.find(nums[i]-1)!=num_set.end()) continue;
            
            long y = nums[i]+1;
            while (num_set.find(y)!=num_set.end()) y += 1;
            long now_length = y-nums[i];

            if (now_length > max_length) max_length = now_length;
            if (max_length > (nums.size()-i-1)) return max_length; 
        }
        return max_length;
    }
};