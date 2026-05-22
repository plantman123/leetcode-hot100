#include<iostream>
#include<deque>
#include<vector>
using namespace std;


// class Solution {
// public:
//     static int max(int a, int b) {
//         if (a>b) return a;
//         return b;
//     }

//     static int min(int a, int b) {
//         if (a>b) return b;
//         return a;
//     }

//     void print_vec(vector<int> a) {
//         for (int i=0;i<a.size();i++) cout << a[i] << " ";
//         cout << endl;
//     }

//     int maxArea(vector<int>& heights) {
//         heights.push_back(10001);
//         vector<int> lidxs;
//         // 单调栈问题，构建递减栈，遇到每一个height的元素都需要进栈，但需要通过出栈操作保证栈内关系
//         // 最大方形出现在曾经作为栈底元素的两侧，栈内保存的是idx
//         vector<int> tops; // 保存出现过的栈顶
//         int max_s = 0;
//         for (int i=0;i<heights.size();i++) {
//             int height = heights[i];
//             for (int j=0;j<tops.size();j++) {
//                 if (heights.size()-1 == i) break;
//                 max_s = max(max_s, min(heights[tops[j]], height)*(i-tops[j]));
//             }
//             if (lidxs.empty() || height <= heights[lidxs.back()]) {
//                 if (lidxs.empty()) tops.push_back(i);
//                 lidxs.push_back(i);
//             }
//             else {
//                 while (!lidxs.empty() && heights[lidxs.back()] < height) {
//                     lidxs.pop_back();
//                 }
//                 if (lidxs.empty()) tops.push_back(i);
//                 lidxs.push_back(i);
//             }
//         }
//         return max_s;
//     }
// };


class Solution {
public:
    static int max2(int a, int b) {
        if (a>b) return a;
        return b;
    }
    int maxArea(vector<int>& heights) {
        int lidx = 0, ridx = heights.size()-1;
        int max_s = 0;
        while (lidx < ridx) {
            if(heights[lidx] < heights[ridx]) {
                max_s = max2(max_s, (ridx-lidx)*heights[lidx]);
                lidx += 1;
            } 
            else {
                max_s = max2(max_s, (ridx-lidx)*heights[ridx]);
                ridx -= 1;
            }
        }
        return max_s;
    }
};