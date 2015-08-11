//
// Created by zhengxx on 15/8/11.
//
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root) {
            _stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = _stack.top();
        int _val = p->val;
        _stack.pop();
        if (p->right) {
            p = p->right;
            while (p) {
                _stack.push(p);
                p = p->left;
            }
        }
        return _val;
    }
private:
    stack<TreeNode *> _stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */