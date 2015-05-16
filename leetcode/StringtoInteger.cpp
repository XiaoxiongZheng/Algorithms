//
// Created by zhengxx on 15/5/16.
//
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        int i = 0, pos = 1;
        while(str[i] == ' ') i++;
        if (str[i] == '-') pos = 0, i++;
        else if (str[i] == '+') i++;
        long ans = 0;
        while(i < str.size() && ans < INT_MAX + long(3))
        {
            if (str[i] > '9' || str[i] < '0') break;
            ans =  ans * 10 + (str[i] - '0');
            i++;
        }
        ans = pos ? ans : -ans;
        if (ans >= INT_MAX) return INT_MAX;
        else if (ans <= INT_MIN) return INT_MIN;
        return ans;
    }
};
