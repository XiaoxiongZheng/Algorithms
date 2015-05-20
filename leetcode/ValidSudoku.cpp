//
// Created by zhengxx on 15/5/20.
//

/**
 * valid sudoku
 * https://leetcode.com/problems/valid-sudoku/
 * time = O(n^2), space = O(n^2)
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            int r[10], c[10];
            memset(r, 0, sizeof(r));
            memset(c, 0, sizeof(c));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (r[board[i][j] - '0'] == 1) return false;
                    else r[board[i][j] - '0'] = 1;
                }
                if (board[j][i] != '.'){
                    if (c[board[j][i] - '0'] == 1) return false;
                    else c[board[j][i] - '0'] = 1;
                }
            }
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                int cube[3][3];
                memset(cube, 0, sizeof(cube));
                for (int k = 0; k < 3; k++)
                    for (int l = 0; l < 3; l++) {
                        int r = i * 3 + k, c = j * 3 + l;
                        if (board[r][c] != '.') {
                            if (cube[board[r][c] - '0'] == 1) return false;
                            else cube[board[r][c] - '0'] = 1;
                        }
                    }
            }
        }
        return true;
    }
};