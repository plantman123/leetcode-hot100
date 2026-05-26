#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    static int min2(int a, int b) {
        if (a < b) return a;
        return b;
    }
    static void print_vec(vector<int> heights) {
        for (int i=0;i<heights.size();i++) {cout << heights[i] << " ";}
        cout << endl;
    }
    int trap(vector<int>& heights) {
        int rains = 0;
        int new_place = 1;
        while (new_place) {
            new_place = 0;
            for (int i=1;i<heights.size()-1;i++) {
                if (heights[i] < heights[i-1] && heights[i] < heights[i+1]) {
                    rains += (min2(heights[i-1], heights[i+1]) - heights[i]);
                    heights[i] = min2(heights[i-1], heights[i+1]);
                    new_place = 1;
                }

                if (heights[i]==heights[i+1] && heights[i-1] > heights[i]) {
                    int j, shortage=0;
                    for (j=i+1;j<heights.size();j++) {
                        if (heights[j] != heights[j-1]) {
                            if (heights[j] < heights[j-1]) {i=j-1;}
                            else shortage = min2(heights[i-1], heights[j]);
                            break;
                        }
                    }

                    if (shortage) {
                        for (int t=i;t<j;t++) {
                            rains += (shortage-heights[t]);
                            heights[t] = shortage;
                        }
                        new_place = 1;
                    }
                }
            }
            print_vec(heights);
        }
        return rains;
    }
};