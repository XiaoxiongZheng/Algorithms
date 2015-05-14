//
// Created by zhengxx on 15/5/14.
//
/**
 * two sum
 * https://leetcode.com/problems/two-sum/
 * time = O(n), space = O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> index;
        for (int i = 0; i < len; i++)
        {
            if (index.find(target - nums[i]) == index.end())
                index[nums[i]] = i + 1;
            else
                return {index[target - nums[i]], i + 1};
        }
    }
};