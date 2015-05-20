//
// Created by zhengxx on 15/5/20.
//

/**
 * search insert position
 * https://leetcode.com/problems/search-insert-position/
 * time = O(logn), space = O(1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size(), start = 0, end = len - 1;
        while (start <= end){
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};