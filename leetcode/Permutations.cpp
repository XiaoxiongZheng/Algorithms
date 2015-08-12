//
// Created by zhengxx on 15/8/12.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> status(nums.size(), false);
        dfs(ans, {}, nums, status);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> path, vector<int>& nums, vector<bool> status) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (status[i]) continue;
            vector<int> _path = path;
            vector<bool> _status = status;
            _status[i] = true;
            _path.push_back(nums[i]);
            dfs(ans, _path, nums, _status);
        }
    }
};