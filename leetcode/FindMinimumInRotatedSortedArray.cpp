//
// Created by zhengxx on 15/8/12.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int start = 0, end = nums.size() - 1;
        if (nums[start] <= nums[end])
            return nums[start];
        int minval = INT_MAX;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[start]){
                minval = min(minval, nums[start]);
                start = mid + 1;
            }
            else if (nums[mid] < nums[start]){
                minval = min(minval, nums[mid]);
                end = mid - 1;
            }
            else{
                minval = min(minval, nums[mid]);
                start++;
            }
        }
        return minval;
    }
};