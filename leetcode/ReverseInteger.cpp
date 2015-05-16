//
// Created by zhengxx on 15/5/16.
//

/**
 * reverse integer
 * https://leetcode.com/problems/reverse-integer/
 * time = O(n), space = O(1)
 */

#include <string>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        long t = abs((long)x), ans = 0;
        while(t)
        {
            ans = 10 * ans + t % 10;
            t = t / 10;
        }
        ans = x > 0 ? ans : -ans;
        if (ans >= INT_MAX || ans <= INT_MIN) return 0;
        return ans;
    }
};