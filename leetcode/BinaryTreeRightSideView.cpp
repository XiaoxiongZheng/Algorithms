//
// Created by zhengxx on 15/7/25.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        if (root->right == nullptr && root->left == nullptr) return {root->val};
        queue<TreeNode *> q;
        TreeNode *p = root;
        TreeNode *bound = (root->right != nullptr) ? root->right : root->left;
        ans.push_back(p->val);
        q.push(p);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            if (tmp == bound) {
                ans.push_back(tmp->val);
                if(tmp->left == nullptr && tmp->right == nullptr) bound = q.back();
                else bound = (tmp->right != nullptr) ? tmp->right : tmp->left;
            }
        }
        return ans;
    }
};