//
// Created by zhengxx on 15/5/21.
//

/**
 * trapping rain water
 * https://leetcode.com/problems/trapping-rain-water/
 * time = O(n), space = O(n)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int len = height.size(), dp[len], lmax = INT_MIN, rmax = INT_MIN;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < len; i++) {
            if (height[i] >= lmax)
                lmax = height[i];
            dp[i] = lmax;
        }
        int ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (height[i] > rmax)
                rmax = height[i];
            else
                ans += min(rmax, dp[i]) - height[i];
        }
        return ans;
    }
};