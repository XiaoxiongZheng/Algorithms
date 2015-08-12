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
    int maxPathSum(TreeNode *root) {
        maxSum(root);
        return maxVal;
    }

    int maxSum(TreeNode *node) {
        if (node == nullptr) return 0;
        int lval = maxSum(node->left), rval = maxSum(node->right), ans = node->val;
        if (lval > 0) ans += lval;
        if (rval > 0) ans += rval;
        maxVal = max(ans, maxVal);
        return max(lval, rval) > 0 ? node->val + max(lval, rval) : node->val;
    }

private:
    int maxVal = INT_MIN;
};