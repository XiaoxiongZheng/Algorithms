//
// Created by zhengxx on 15/7/25.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        if (len == 2) return max(nums[0], nums[1]);
        vector<int> result(len, 0);
        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            result[i] = max(result[i - 1], result[i - 2] + nums[i]);
        }
        return result[len - 1];
    }
};