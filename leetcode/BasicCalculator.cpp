//
// Created by zhengxx on 15/8/8.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int calculate(string s) {
        stack<int> _stack1;
        int sign = 1, num = 0, ans = 0;
        _stack1.push(1);
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            }
            else if (c == '+' || c == '-') {
                ans = ans + _stack1.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            }
            else if (c == '(') {
                _stack1.push(sign * _stack1.top());
                sign = 1;
            }
            else if (c == ')') {
                ans = ans + _stack1.top() * sign * num;
                num = 0;
                _stack1.pop();
                sign = 1;
            }
        }
        if (num) {
            ans = ans + _stack1.top() * sign * num;
        }
        return ans;
    }
};