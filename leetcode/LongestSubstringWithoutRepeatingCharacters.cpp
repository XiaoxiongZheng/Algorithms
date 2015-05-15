//
// Created by zhengxx on 15/5/14.
//

/**
 * longest substring without repeating characters
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * time = O(n), space = O(1)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int a[256], len = s.size(), ans = INT_MIN, j = 0;
        memset(a, -1, sizeof(a));
        for (int i = 0; i < len; i++)
        {
            if (a[s[i]] < j) a[s[i]] = i;
            else
            {
                ans = max(i - j, ans);
                j = a[s[i]] + 1, a[s[i]] = i;
            }
        }
        ans = max(len - j, ans);
        return ans;
    }
};