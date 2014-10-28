#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	bool index = false;

	bool hasPathSum(TreeNode *root, int sum)
	{
		if (root == NULL)
			return index;
		dfs(sum, root);
		return index;
	}

	void dfs(int remain, TreeNode *node)
	{
		if (index)
			return;
		if (remain == node->val && node->left == NULL && node->right == NULL){
			index = true;
			return;
		}
		if (node->left)
			dfs(remain - node->val, node->left);
		if (node->right)
			dfs(remain - node->val, node->right);
	}
};