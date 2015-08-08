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
        int len = s.size(), temp;
        stack<int> istack;
        stack<char> cstack;
        for (int i = 0; i < len;) {
            if (s[i] == ' ') i++;
            else if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                while (j < len && s[j] >= '0' && s[j] <= '9')
                    j++;
                int val = atoi(s.substr(i, j - i).c_str());
                if (!cstack.empty() && (cstack.top() == '+' || cstack.top() == '-')) {
                    int temp = istack.top();
                    istack.pop();
                    switch (cstack.top()) {
                        case '+':
                            istack.push(temp + val);
                            break;
                        case '-':
                            istack.push(temp - val);
                            break;
                        default:
                            break;
                    }
                    cstack.pop();
                }
                else {
                    istack.push(val);
                }
                i = j;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
                cstack.push(s[i++]);
            }
            else {
                if (cstack.top() == '(') {
                    cstack.pop();
                    i++;
                    continue;
                }
                int t1 = istack.top();
                istack.pop();
                int t2 = istack.top();
                istack.pop();
                if (cstack.top() == '+')
                    istack.push(t1 + t2);
                else
                    istack.push(t2 - t1);
                cstack.pop();
            }
        }
        if (!cstack.empty()) {
            int t1 = istack.top();
            istack.pop();
            int t2 = istack.top();
            istack.pop();
            if (cstack.top() == '+')
                return t1+t2;
            else
                return t2-t1;
        }
        return istack.top();
    }
};