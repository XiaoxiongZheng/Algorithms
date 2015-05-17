//
// Created by zhengxx on 15/5/17.
//

/**
 * 4 sum
 * https://leetcode.com/problems/4sum/
 * time = O(n^3), space = O(1)
 */

#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                int t = target - nums[i] - nums[j], s = j + 1, e = len - 1;
                while(s < e){
                    if (s != j + 1 && nums[s] == nums[s - 1])
                        s++;
                    else if (e != len - 1 && nums[e] == nums[e + 1])
                        e--;
                    else if (nums[s] + nums[e] == t){
                        vector<int> vec = {nums[i], nums[j], nums[s], nums[e]};
                        ans.push_back(vec);
                        s++, e--;
                    }
                    else if (nums[s] + nums[e] > t) e--;
                    else s++;
                }
            }
        }
        return ans;
    }
};
