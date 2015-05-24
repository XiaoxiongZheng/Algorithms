//
// Created by zhengxx on 15/5/21.
//
/**
 * multiply strings
 * https://leetcode.com/problems/multiply-strings/
 * time = O(m * n), space = O(m + n)
 */

#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        size_t len1 = num1.size(), len2 = num2.size();
        string ans = "0";

        for (int i = len2 - 1; i >= 0; i--) {
            if (num2[i] == '0') continue;
            string t = getMul(num1, num2[i]);
            for (int j = len2 - 1; j > i; j--)
                t.push_back('0');
            ans = getAdd(ans, t);
        }
        return ans;
    }

    string getAdd(string& num1, string& num2){
        int len1 = num1.size(), len2 = num2.size(), carry = 0;
        string ans = "";
        for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--){
            if (i >= 0) carry += num1[i] - '0';
            if (j >= 0) carry += num2[j] - '0';
            ans = to_string(carry % 10) + ans;
            carry /= 10;
        }
        return ans;
    }

    string getMul(string num, char n) {
        if (n == '1') return num;
        int d = n - '0';
        int len = num.size(), carry = 0;
        string ans = "";
        for (int i = len - 1; i >= 0 || carry; i--) {
            if(i >= 0) carry += (num[i] - '0') * d;
            ans = to_string(carry % 10) + ans;
            carry = carry / 10;
        }
        return ans;
    }
};