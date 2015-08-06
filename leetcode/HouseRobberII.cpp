//
// Created by zhengxx on 15/8/5.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int len = nums.size();
        return max(helprob(nums, 0, len - 2), helprob(nums, 1, len - 1));
    }

    int helprob(vector<int>& nums, int start, int end) {
        int len = end-start+1, dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[start], dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[len-1];
    }
};