#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    static void print_vec(vector<int> heights) {
        for (int i=0;i<heights.size();i++) {cout << heights[i] << " ";}
        cout << endl;
    }

    int trap(vector<int>& heights) {
        if (heights.size() < 3) return 0;
        int rains = 0;
        int i, j;
        // 顺序遍历
        for (i=0;i<heights.size()-2;i++) {
            if (heights[i+1] < heights[i]) {
                vector<int> new_heights = heights;
                // print_vec(new_heights);
                int new_rains = 0;
                for (j=i+1;j<heights.size();j++) {
                    if (heights[j] >= heights[i]) {
                        heights = new_heights;
                        rains += new_rains;
                        i=j-1;
                        break;
                    }
                    new_heights[j] = heights[i];
                    new_rains += (heights[i]-heights[j]);
                }
            }
        }

        // 逆序遍历
        for (j=heights.size()-1;j>1;j--) {
            if (heights[j-1] < heights[j]) {
                vector<int> new_heights = heights;
                int new_rains = 0;
                for (i=j-1;i>=0;i--) {
                    if (heights[i] >= heights[j]) {
                        heights = new_heights;
                        rains += new_rains;
                        j=i+1;
                        break;
                    }
                    new_heights[i] = heights[j];
                    new_rains += (heights[j]-heights[i]);
                }
            }
        }

        return rains;
    }
};