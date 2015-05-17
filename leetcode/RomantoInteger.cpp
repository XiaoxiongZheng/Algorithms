//
// Created by zhengxx on 15/5/17.
//

/**
 * roman to integer
 * https://leetcode.com/problems/roman-to-integer/
 * time = O(n), space = O(1)
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int m[256];
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && m[s[i]] > m[s[i - 1]])
                ans += m[s[i]] - 2 * m[s[i - 1]];
            else
                ans += m[s[i]];
        }
        return ans;
    }
};