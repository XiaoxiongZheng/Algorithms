//
// Created by zhengxx on 15/5/18.
//

/**
 * next permutation
 * https://leetcode.com/problems/next-permutation/
 * time = O(n), space = O(1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int len = nums.size(), i = len - 1;
        for (; i >= 0; i--)
            if (i == 0 || nums[i] > nums[i - 1])
                break;
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int j = len - 1; j >= i; j--){
            if (nums[j] > nums[i - 1]) {
                swap(nums[j], nums[i - 1]);
                reverse(nums.begin() + i, nums.end());
                return ;
            }
        }
    }
};