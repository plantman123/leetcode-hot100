#include<vector>
#include<deque>
#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
    static void print_vec(deque<int> vec) {
        for (int i=0;i<vec.size();i++) cout << vec[i] << " ";
        cout << endl;
    }

    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> sicnt;
        for (int i=0;i<nums.size();i++) {
            sum += nums[i];
            if (sum == k) res += 1;
            res += sicnt[sum-k];
            sicnt[sum] += 1;
        }
        return res;
    }
};
