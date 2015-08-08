//
// Created by zhengxx on 15/8/9.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return {};
        vector<int> left(len, 1);
        vector<int> right(len, 1);

        for (int i = 1; i < len; i++)
            left[i] = left[i - 1] * nums[i - 1];
        for (int i = len - 2; i >= 0; i--)
            right[i] = right[i - 1] * nums[i + 1];
        vector<int> ans(len, 0);
        for (int i = 0; i < len; i++)
            ans[i] = left[i] * right[i];
        return ans;
    }
};