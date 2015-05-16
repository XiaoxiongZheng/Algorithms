//
// Created by zhengxx on 15/5/16.
//

/**
 * palindrome number
 * https://leetcode.com/problems/palindrome-number/
 * time = O(n), space = O(1)
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};