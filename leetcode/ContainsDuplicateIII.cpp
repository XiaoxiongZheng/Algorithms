//
// Created by zhengxx on 15/8/6.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        map<int, int> m;
        for (int i = 0; i < len; i++) {
            if (i - k > 0 && m.find(nums[i - k - 1])!=m.end()) m.erase(nums[i - k - 1]);
            auto iter = m.lower_bound(nums[i] - t);
            if (iter != m.end() && abs(iter->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};