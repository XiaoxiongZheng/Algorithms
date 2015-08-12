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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack < TreeNode * > _stack;
        _stack.push(root);

        while (true) {
            TreeNode *p = _stack.top();
            ans.push_back(p->val);
            _stack.pop();
            if (p->right) _stack.push(p->right);
            if (p->left) _stack.push(p->left);
            if (_stack.empty()) break;
        }
        return ans;
    }
};