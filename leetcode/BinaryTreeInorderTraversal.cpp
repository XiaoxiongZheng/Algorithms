//
// Created by zhengxx on 15/8/12.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode *> _stack;
        TreeNode *p = root;
        while(true) {
            while (p) {
                _stack.push(p);
                p = p->left;
            }
            if (_stack.empty()) break;
            p = _stack.top();
            ans.push_back(p->val);
            _stack.pop();
            p = p->right;
        }
        return ans;
    }
};