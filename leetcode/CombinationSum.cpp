//
// Created by zhengxx on 15/5/20.
//

/**
 * combination sum
 * https://leetcode.com/problems/combination-sum/
 * time = O(n!), space = O(n)
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path);
        return ans;
    }

    void dfs(vector<int> &candidates, int pos, int gap, vector<int> &path) {
        if (gap == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (gap < candidates[i]) return;
            path.push_back(candidates[i]);
            dfs(candidates, i, gap - candidates[i], path);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
};