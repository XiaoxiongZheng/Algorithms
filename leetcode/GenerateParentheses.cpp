//
// Created by zhengxx on 15/5/18.
//

#include <vector>
#include <string>

using namespace std;

vector<string> ans;

class Solution {
public:
    // todo stack version
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        dfs("", n, n);
        return ans;
    }

    void dfs(string path, int n1, int n2) {
        if (n1 < 0 || n2 < 0) return;
        else if (n1 == n2 && n1 == 0)
            ans.push_back(path);
        else if (n1 - n2 > 0) return;
        else if (n1 - n2 == 0) {
            path.push_back('(');
            dfs(path, n1 - 1, n2);
            path.pop_back();
        }
        else {
            path.push_back('(');
            dfs(path, n1 - 1, n2);
            path.pop_back();
            path.push_back(')');
            dfs(path, n1, n2 - 1);
            path.pop_back();
        }
    }


};