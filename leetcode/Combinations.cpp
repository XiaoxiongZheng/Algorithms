//
// Created by zhengxx on 15/8/12.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(ans, path, 1, n, k);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> path, int start, int end, int k) {
        if (k == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i <= end - k + 1; i++){
            vector<int> temp = path;
            temp.push_back(i);
            dfs(ans, temp, i+1, end, k-1);
        }
    }

};