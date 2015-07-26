//
// Created by zhengxx on 15/7/25.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        revert(nums.begin(), nums.begin() + k);
        revert(nums.begin() + k, nums.end());
        revert(nums.begin(), nums.end());
    }

private:
    void revert(vector<int>::iterator begin, vector<int>::iterator end) {
        int len = end - begin;
        for (int i = 0; i < len / 2; i++) {
            swap(*begin, *(end - i - 1));
        }
    }
};
