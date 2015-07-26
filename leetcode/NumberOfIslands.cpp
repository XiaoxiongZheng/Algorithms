//
// Created by zhengxx on 15/7/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        n = grid.size(), m = grid[0].size();
        int count = 0;
        vector<vector<bool>> ok(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !ok[i][j]){
                    bfs(grid, i, j, ok);
                    count++;
                }
            }
        return count;
    }
private:
    int m, n;
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &ok)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        ok[i][j] = true;
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            if (r - 1 >= 0 && grid[r - 1][c] == '1' && !ok[r - 1][c]) q.push(make_pair(r - 1, c)), ok[r - 1][c] = true;
            if (r + 1 < n && grid[r + 1][c] == '1' && !ok[r + 1][c]) q.push(make_pair(r + 1, c)), ok[r + 1][c] = true;
            if (c + 1 < m && grid[r][c + 1] == '1' && !ok[r][c + 1]) q.push(make_pair(r, c + 1)), ok[r][c + 1] = true;
            if (c - 1 >= 0 && grid[r][c - 1] == '1' && !ok[r][c - 1]) q.push(make_pair(r, c - 1)), ok[r][c - 1] = true;
            q.pop();
        }
    }
};