//
// Created by zhengxx on 15/5/18.
//

/**
 * implement strStr()
 * https://leetcode.com/problems/implement-strstr/
 * time = O(m * n), space = O(1)
 */

#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.size() > haystack.size()) return -1;
        int len1 = haystack.size(), len2 = needle.size();
        for (int i = 0; i < len1 - len2 + 1; i++){
            int j = 0;
            for (; j < len2; j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == len2) return i;
        }
        return -1;
    }
};