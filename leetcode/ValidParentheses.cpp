//
// Created by zhengxx on 15/5/17.
//

/**
 * valid parentheses
 * https://leetcode.com/problems/valid-parentheses/
 * time = O(n), space = O(n)
 */

#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty() || m[st.top()] != s[i])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};