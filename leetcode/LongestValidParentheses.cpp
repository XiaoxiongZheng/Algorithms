//
// Created by zhengxx on 15/5/19.
//

/**
 * longest valid parentheses
 * https://leetcode.com/problems/longest-valid-parentheses/
 * time = O(n), space = O(n)
 */

#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size(), ans = 0;
        int dp[len];
        memset(dp, 0, sizeof(dp));
        for (int i = len - 2; i >= 0; i--) {
            int match = i + dp[i + 1] + 1;
            if (s[i] == '(' && match < len && s[match] == ')'){
                dp[i] = dp[i + 1] + 2;
                if (match + 1 < len) dp[i] += dp[match + 1];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};