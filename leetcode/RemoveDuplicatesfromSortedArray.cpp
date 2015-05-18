//
// Created by zhengxx on 15/5/18.
//

/**
 * remove duplicates
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * time = O(n), space = O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int i = 0, j = 1, len = nums.size();
        for (; j < len; j++){
            if (nums[j] != nums[j - 1]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};