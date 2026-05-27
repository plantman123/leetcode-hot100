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
        int res = 0;
        int window = nums.size();
        while (window) {
            int sum = 0;
            for (int i=0;i<window;i++) sum += nums[i];
            if (sum == k) res += 1;
            for (int bias=1;bias+window-1<nums.size();bias++) {
                sum -= nums[bias-1];
                sum += nums[bias+window-1];
                if (sum == k) res += 1;
            }
            window -= 1;
        }
        return res;
    }
};
