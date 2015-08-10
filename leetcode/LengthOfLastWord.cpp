//
// Created by zhengxx on 15/8/10.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), ans = 0, i = len - 1;
        while (i >= 0 && s[i] == ' ') i--;;
        if (i < 0) return 0;
        for (int j = i; j >= 0; j--)
            if (s[j] == ' ')
                return i - j;
        return i + 1;
    }
};