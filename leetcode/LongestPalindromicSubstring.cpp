//
// Created by zhengxx on 15/5/15.
//

/**
 * longest substring without repeating character
 * https://leetcode.com/problems/longest-palindromic-substring/
 * time = O(n^2), space = O(n^2)
 */

#include <iostream>
#include <string>
using namespace std;

bool dp[1001][1001];

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return s;
        memset(dp, false, sizeof(dp));
        string ans = s.substr(0, 1);
        int n = s.size();
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int l = 2; l <= n; l++)
            for (int i = 0; i < n - l + 1; i++)
                if (s[i] == s[i + l - 1] && (l == 2 || dp[i + 1][i + l - 2])) {
                    dp[i][i + l - 1] = true;
                    if (ans.size() < l) ans = s.substr(i, l);
                }
        return ans;
    }
};
