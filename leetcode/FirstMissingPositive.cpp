//
// Created by zhengxx on 15/5/21.
//

/**
 * first missing positive
 * https://leetcode.com/problems/first-missing-positive/
 * time = O(n), space = O(1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len;){
            if (nums[i] <= 0 || nums[i] >= len || nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) i++;
            else swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < len; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return len + 1;
    }
};