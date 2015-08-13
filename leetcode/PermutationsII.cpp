//
// Created by zhengxx on 15/8/13.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        dfs(ans, nums, {});
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &remain, vector<int> path) {
        if (remain.size() == 0){
            ans.push_back(path);
            return ;
        }
        for (int i = 0; i < remain.size(); i++) {
            if (i > 0 && remain[i] == remain[i-1]) continue;
            vector<int> _remain(remain);
            vector<int> temp(path);
            temp.push_back(_remain[i]);
            _remain.erase(_remain.begin()+i);
            dfs(ans, _remain, temp);
        }
    }
};