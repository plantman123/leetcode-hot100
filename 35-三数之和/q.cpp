#include<vector>
#include<algorithm>
#include<unordered_set>
#include<iostream>
using namespace std;


class Solution {
public:
    typedef struct tuple{
        int i,ldx,rdx;
        tuple(int a1, int b1, int c1): i(a1), ldx(b1), rdx(c1) {}
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        vector<tuple> num_tups;
        sort(nums.begin(), nums.end());

        for (int i=0;i<nums.size()-2;i++) {
            if (i>0) {if (nums[i] == nums[i-1]) continue;}
            int ldx = i+1, rdx = nums.size()-1, opt=0;
            int tarnum = -nums[i];
            while(ldx < rdx) {
                int numsum = nums[ldx] + nums[rdx];
                if (numsum == tarnum) {
                    tuple new_tup(nums[i], nums[ldx], nums[rdx]);
                    int in_tups = 0;
                    for (int j=0;j<num_tups.size();j++) {
                        if (num_tups[j].i == nums[i] && num_tups[j].ldx == nums[ldx]) in_tups = 1;
                    }
                    if (!in_tups){
                        vector<int> result;
                        result.push_back(nums[i]);
                        result.push_back(nums[ldx]);
                        result.push_back(nums[rdx]);
                        results.push_back(result);
                        num_tups.push_back(new_tup);
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

        for (auto i=0;i<num_tups.size();i++) {
            cout << num_tups[i].i << " " << num_tups[i].ldx << "" << num_tups[i].rdx << endl;
        }
        return results;
    }
};