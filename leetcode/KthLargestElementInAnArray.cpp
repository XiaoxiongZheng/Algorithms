//
// Created by zhengxx on 15/8/5.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> pq;
        int len = nums.size();
        for (int i = 0; i < len; i++)
            pq.push(nums[i]);
        while (--k) {
            pq.pop();
        }
        return pq.top();
    }
};