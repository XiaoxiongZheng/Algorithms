//
// Created by zhengxx on 15/8/6.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), dp[m][n], ans = -1;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = matrix[0][0] == '1' ? 1 : 0;
        for (int i = 1; i < m; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (dp[i-1][j-1] && matrix[i][j] == '1' && helpSquare(matrix, i, j, dp[i-1][j-1]))
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
                ans = max(dp[i][j], ans);
            }
        return ans*ans;
    }

    bool helpSquare(vector<vector<char>>& matrix, int i, int j, int k) {
        for (int c = i - k; c < i; c++) {
            if (matrix[i][c] == '0') return false;
        }
        for (int c = j - k; c < j; c++) {
            if (matrix[c][j] == '0') return false;
        }
        return true;
    }
};