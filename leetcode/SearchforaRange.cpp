//
// Created by zhengxx on 15/5/20.
//
/**
 * search for a range
 * https://leetcode.com/problems/search-for-a-range/
 * time = O(logn), space =O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        while (start <= end){
            mid = (start + end) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        if (start > end) return {-1, -1};
        start = mid, end = mid;
        for (int i = start - 1, j = end + 1; i >= 0 || j < nums.size(); i--, j++){
            if (i >= 0 && nums[i] == target) start = i;
            if (j < nums.size() && nums[j] == target) end = j;
        }

        return {start, end};
    }
};