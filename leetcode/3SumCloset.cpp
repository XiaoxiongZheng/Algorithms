//
// Created by zhengxx on 15/5/17.
//

/**
 * 3Sum Closet
 * https://leetcode.com/problems/3sum-closest/
 * time = O(n^2), space = O(1)
 */

#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int len = nums.size();
        long long mn = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            int t = target - nums[i], s = i + 1, e = len - 1;
            while (s < e) {
                if (nums[s] + nums[e] == t) return target;
                else {
                    int sum = nums[i] + nums[s] + nums[e];
                    mn = abs(sum - target) < abs(mn - target) ? sum : mn;
                    if (nums[s] + nums[e] > t) e--;
                    else s++;
                }
            }
        }
        return mn;
    }
};