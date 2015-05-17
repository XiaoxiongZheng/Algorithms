//
// Created by zhengxx on 15/5/17.
//


/**
 * longest common prefix
 * https://leetcode.com/problems/longest-common-prefix/
 * time = O(n), space = O(1)
 */


#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0;; i++)
        {
            char c;
            if (strs[0].size() > i) c = strs[0][i];
            else return ans;
            for (int j = 1; j < strs.size(); j++)
                if (strs[j].size() <= i || strs[j][i] != c)
                    return ans;
            ans.append(1, c);
        }
    }
};
