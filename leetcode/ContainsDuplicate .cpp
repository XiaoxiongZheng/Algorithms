//
// Created by zhengxx on 15/8/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> um;
        for (int i = 0; i < nums.size(); i++) {
            if (um[nums[i]]) return false;
            else um[nums[i]] = true;
        }
        return true;
    }
};