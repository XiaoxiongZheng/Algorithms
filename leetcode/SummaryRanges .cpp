//
// Created by zhengxx on 15/8/7.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};
        if (len == 1) return {to_string(nums[0])};
        vector<string> result;
        int j = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] - nums[i-1] == 1) continue;
            else {
                string ans = "";
                if (j == i-1) ans = to_string(nums[i-1]);
                else ans = to_string(nums[j]) + "->" + to_string(nums[i-1]);
                result.push_back(ans);
                j = i;
            }
        }
        string ans;
        if (j != len - 1) ans = to_string(nums[j]) + "->" + to_string(nums[len - 1]);
        else ans = to_string(nums[j]);
        result.push_back(ans);
        return result;
    }
};