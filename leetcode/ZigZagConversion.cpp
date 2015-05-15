//
// Created by zhengxx on 15/5/15.
//

/**
 * zigzag conversion
 * https://leetcode.com/problems/zigzag-conversion/
 * time = O(n), space = O(n)
 */

#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() == 0) return s;
        int len = s.size();
        string ans = "";
        for (int i = 0; i < numRows; i++)
            for (int j = 0, index = i; index < len;j++, index = (2 * numRows - 2) * j + i)
            {
                ans.append(1, s[index]);
                if (i == 0 || i == numRows - 1) continue;
                if (index + (numRows - i - 1) * 2 < len)
                    ans.append(1, s[index + (numRows - i - 1) * 2]);
            }
        return ans;
    }
};
