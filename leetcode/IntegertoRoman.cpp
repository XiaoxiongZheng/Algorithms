//
// Created by zhengxx on 15/5/17.
//

/**
 * integer to roman
 * https://leetcode.com/problems/integer-to-roman/
 * time = O(n), space = O(n)
 */

#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        for (int i = 0; num > 0; ++i)
        {
            int count = num / a[i];
            num %= a[i];
            for (; count > 0; --count) ans += roman[i];
        }
        return ans;
    }
};