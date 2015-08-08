//
// Created by zhengxx on 15/8/8.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode *lnode = lowestCommonAncestor(root->left, p, q), *rnode = lowestCommonAncestor(root->right, p, q);
        if (lnode && rnode) return root;
        if (lnode) return lnode;
        if (rnode) return rnode;
        return nullptr;
    }
};