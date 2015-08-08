//
// Created by zhengxx on 15/8/9.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t || s.size() != t.size()) return false;
        int len = s.size(), cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < len; i++)
            cnt[s[i] - 'a']++;
        for (int i = 0; i < len; i++)
            if (--cnt[t[i] - 'a'] < 0)
                return false;
        return true;
    }
};