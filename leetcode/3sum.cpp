//
// Created by zhengxx on 15/5/12.
//


/**
 *      https://leetcode.com/problems/3sum/
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < len - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            for (int j = i + 1, k = len - 1; j < k;)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                if (k < len - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;
                }
                if (nums[j] + nums[k] == target)
                {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    result.push_back(tmp);
                    j++, k--;
                }
                else if (nums[j] + nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};
