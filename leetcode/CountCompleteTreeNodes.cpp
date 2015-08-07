//
// Created by zhengxx on 15/8/6.
//

#include <iostream>
#include <cmath>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int hl = 0, hr = 0;
        TreeNode *p = root, *q = root;
        while (p) {
            hl++;
            p = p->left;
        }
        while (q) {
            hr++;
            q = q->right;
        }
        if (hl == hr) return pow(2, hl) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};