//
// Created by zhengxx on 15/8/12.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
        return isValidBST(root->left) && isValidBST(root->right) && helpBST(root);
    }

    bool helpBST(TreeNode *node) {
        TreeNode *p = node, *q = node;
        if (p->left) {
            p = p->left;
            while(p->right) p = p->right;
            if (node->val <= p->val) return false;
        }
        if (q->right) {
            q = q->right;
            while (q->left) q = q->left;
            if (node->val >= q->val) return false;
        }
        return true;
    }
};