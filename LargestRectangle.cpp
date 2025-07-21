//You are given an array of integers heights where heights[i] represents the height of a bar.The width of each bar is 1.
//
//Return the area of the largest rectangle that can be formed among the bars.
//
//Note: This chart is known as a histogram.
//
//	Example 1 :
//
//		Input : heights = [7, 1, 7, 2, 2, 4]
//
//		Output : 8
//	Example 2 :
//
//		Input : heights = [1, 3, 7]
//
//		Output : 7

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;

        stack<int> index;
        vector<int>left(n, -1);
        vector<int> right(n, n);

        for (int i = 0; i <= n; i++) {
            while (!index.empty() && heights[index.top()] >= heights[i]) {
                right[index.top()] = i;
                index.pop();
            }
            if (!index.empty()) {
                left[i] = index.top();
            }
            index.push(i);
        }

        for (int i = 0; i < n; i++) {
            max_area = max(max_area, heights[i] * (right[i] - left[i] - 1));
        }
        return max_area;
    }
};