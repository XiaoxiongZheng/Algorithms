#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum)
	{

		vector<vector<int> > result;
		if (root == NULL)
			return result;
		vector<int> path;
		dfs(sum, root, result, path);
		return result;
	}

	void dfs(int remain, TreeNode *node, vector<vector<int> > &result, vector<int> path)
	{
		path.push_back(node->val);
		if (remain == node->val && node->left == NULL && node->right == NULL)
		{
			result.push_back(path);
			return;
		}
		if (node->left)
			dfs(remain - node->val, node->left, result, path);
		if (node->right)
			dfs(remain - node->val, node->right, result, path);
	}
}S;

int main()
{
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	t1->left = t2;
	S.pathSum(t1, 1);

}