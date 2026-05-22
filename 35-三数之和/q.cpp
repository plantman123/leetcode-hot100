#include<vector>
#include<algorithm>
#include<unordered_set>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        unordered_set<int> num_set;  // 保存已有的数字
        sort(nums.begin(), nums.end());
        int findz = 0;
        for (int i=0;i<nums.size()-2;i++) {
            if (i>0) {if (nums[i] == nums[i-1]) continue;}
            int ldx = i+1, rdx = nums.size()-1, opt=0;
            int tarnum = -nums[i];
            while(ldx < rdx) {
                int numsum = nums[ldx] + nums[rdx];
                if (numsum == tarnum) {
                    if (!(num_set.find(nums[ldx])!=num_set.end() && num_set.find(nums[rdx])!=num_set.end() && num_set.find(nums[i])!=num_set.end())){
                        num_set.insert(nums[ldx]);
                        num_set.insert(nums[rdx]);
                        num_set.insert(nums[i]);
                        vector<int> result;
                        result.push_back(nums[i]);
                        result.push_back(nums[ldx]);
                        result.push_back(nums[rdx]);
                        results.push_back(result);
                        if (nums[i] == 0 && nums[ldx] == 0 && nums[rdx] == 0) findz = 1;
                    }

                    else if (nums[ldx] == 0 && nums[rdx] == 0 && nums[i] == 0 && findz == 0) {
                        vector<int> result;
                        result.push_back(0);
                        result.push_back(0);
                        result.push_back(0);
                        results.push_back(result);
                        findz = 1;
                    }
                    rdx -= 1;
                }

                if (numsum > tarnum) {
                    rdx -= 1;
                }
                
                if (numsum < tarnum) {
                    ldx += 1;
                }
            }
        }
        for (auto i=num_set.begin();i!=num_set.end();i++) {
            cout << (*i) << endl;
        }
        return results;
    }
};