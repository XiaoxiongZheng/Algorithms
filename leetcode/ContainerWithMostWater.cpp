//
// Created by zhengxx on 15/5/17.
//

/**
 * container with most water
 * https://leetcode.com/problems/container-with-most-water/
 * time = O(n), space = O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 0) return 0;
        int s = 0, e = height.size() - 1, ans = INT_MIN;
        while (s < e)
        {
            ans = max(ans, min(height[s], height[e]) * (e - s));
            if (height[s] <= height[e])
                s++;
            else
                e--;
        }
        return ans;
    }
};