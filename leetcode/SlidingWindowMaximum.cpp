//
// Created by zhengxx on 15/8/2.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0 || k <= 0) return {};
        if (len <= k) {
            int temp = nums[0];
            for (int i = 0; i < len; i++)
                temp = max(temp, nums[i]);
            return {temp};
        }
        vector<int> result;
        vector<pair<int, int>> vec(len);
        int front = 0, tail = 0;
        for (int i = 0; i < len; i++) {
            pair<int, int> p(nums[i], i);
            while (tail >= front && vec[tail].first < nums[i])
                tail--;
            tail++;
            vec[tail] = p;
            while (front < tail && vec[front].second < i - k + 1)
                front++;
            if(i >= k - 1) result.push_back(vec[front].first);
        }
        return result;
    }
};