//
// Created by zhengxx on 15/5/16.
//

/**
 * regular expression matching
 * https://leetcode.com/problems/regular-expression-matching/
 * time = O(n^2), space = O(n^2)
 */

#include <string>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[1] == '*')
            return (isMatch(s, p.substr(2))) ||
                    (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        else
            return !s.empty() &&
                    (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }

    bool isMatch_dp(string s, string p)
    {
        int m = s.size(), n = p.size();
        bool f[m + 1][n + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;

        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && p[j - 1] == '*' && f[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j];
        return f[m][n];
    }
};
