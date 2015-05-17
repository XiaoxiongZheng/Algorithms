//
// Created by zhengxx on 15/5/17.
//

/**
 *
 */

#include <vector>
#include <string>

using namespace std;

const string phone[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs(ans, digits, "");
        return ans;
    }

    void dfs(vector<string> &ans, string digits, string path) {
        if (digits.size() == 0) {
            if(path != "") ans.push_back(path);
            return;
        }
        for (int i = 0; i < phone[digits[0] - '0'].size(); i++) {
            string temp = path;
            temp += phone[digits[0] - '0'][i];
            dfs(ans, digits.substr(1), temp);
        }
    }
};