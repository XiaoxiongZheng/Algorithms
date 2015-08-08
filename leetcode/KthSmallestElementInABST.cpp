//
// Created by zhengxx on 15/8/8.
//

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> _stack;
        TreeNode *p = root;
        while (true) {
            while (p) {
                _stack.push(p);
                p = p->left;
            }
            if (_stack.empty()) break;
            p = _stack.top();
            if (--k == 0) return p->val;
            _stack.pop();
            p = p->right;
        }
        return 0;
    }
};