//
// Created by zhengxx on 15/5/18.
//

/**
 * remove element
 * https://leetcode.com/problems/remove-element/
 * time = O(n), space = O(1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.size() == 0) return 0;
        int len = nums.size(), i = -1, j = 0;
        for (; j < len; j++) {
            if (nums[j] != val) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return i + 1;
    }
};