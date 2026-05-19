#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nzidx = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]) {
                nums[nzidx] = nums[i];
                nzidx += 1;
            }
        }
        for (int i=nzidx;i<nums.size();i++) {
            nums[i] = 0;
        }
    }
};
