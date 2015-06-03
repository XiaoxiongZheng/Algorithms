//
// Created by zhengxx on 15/6/3.
//

/**
 * largest rectangle in histogram
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 * time = O(n), space = O(n)
 * 单调栈解法
 */
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int len = height.size(), left[len], right[len];
        stack<int> stk;
        memset(left, -1, sizeof(left));
        fill(right, right + len, len);

        for (int i = 0; i < len; i++){
            while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for (int i = len - 1; i >= 0; i--){
            while (!stk.empty() && height[stk.top()] >= height[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }
        int ans = 0;
        for (int i = 0; i < len; i++)
            ans = max(ans, (right[i] - left[i] - 1) * height[i]);

        return ans;
    }
};