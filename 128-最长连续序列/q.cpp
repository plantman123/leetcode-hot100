#include<string>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        long base = 1000000000;
        long min_num = base, max_num = -base;
        unordered_map<long, int> num_map; 
        for (int i=0;i<nums.size();i++) {
            if (min_num > nums[i]) {min_num = nums[i];}
            if (max_num < nums[i]) {max_num = nums[i];}
            num_map[nums[i]] = 1;
        }

        long max_length = 0;
        for (int i=0;i<nums.size();i++) {
            if (num_map[nums[i]-1]) continue;
            
            long y = nums[i]+1;
            while (num_map[y]) y += 1;
            long now_length = y-nums[i];

            if (now_length > max_length) max_length = now_length;
            if (max_length > (nums.size()-i-1)) return max_length; 
        }
        return max_length;
    }
};