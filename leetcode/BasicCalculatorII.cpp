//
// Created by zhengxx on 15/8/9.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> _stack;
        int num = 0, ans = 0, len = s.size();
        char sign = '+';
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] != ' ' || i == len - 1) {
                if (sign == '-')
                    _stack.push(-num);
                if (sign == '+')
                    _stack.push(num);
                if (sign == '*') {
                    int temp = _stack.top();
                    _stack.pop();
                    _stack.push(temp * num);
                }
                if (sign == '/') {
                    int temp = _stack.top();
                    _stack.pop();
                    _stack.push(temp / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        while (!_stack.empty()) {
            ans += _stack.top();
            _stack.pop();
        }
        return ans;
    }
};