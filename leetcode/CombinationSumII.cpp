//
// Created by zhengxx on 15/5/20.
//

/**
 * combination sum ii
 * https://leetcode.com/problems/combination-sum-ii/
 * time = O(n!), space = O(n)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int> &candidates, int pos, int gap) {
        if (gap == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (i != pos && candidates[i] == candidates[i - 1]) continue;
            if (gap < candidates[i]) return;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, gap - candidates[i]);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> ans;
    vector<int> path;
};