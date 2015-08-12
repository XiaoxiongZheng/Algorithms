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
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> _stack;
        vector<int> ans;
        TreeNode *p = root->left, *pre = root;
        _stack.push(root);
        while(!_stack.empty()) {
            while (p){
                _stack.push(p);
                p = p->left;
            }
            p = _stack.top();
            while (!p->right || p->right == pre) {
                ans.push_back(p->val);
                pre = p;
                _stack.pop();
                if (_stack.empty()) break;
                p = _stack.top();
            }
            p = p->right;
        }
        return ans;
    }
};