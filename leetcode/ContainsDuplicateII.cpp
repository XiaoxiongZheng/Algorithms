//
// Created by zhengxx on 15/8/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = i;
            }
            else {
                if (abs(um[nums[i]] - i) <= k) return true;
                um[nums[i]] = i;
            }
        }
        return false;
    }
};