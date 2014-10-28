#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public :
	
	int minsize = INT_MAX;

	int minDepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int step = 1;
		dfs(step, root);
		return minsize;
	}
	void dfs(int step, TreeNode *node)
	{
		if (step >= minsize)
			return;
		if (node->left == NULL && node->right == NULL)
		{
			if (step < minsize)
				minsize = step;
			return;
		}
		if (node->left)
			dfs(step + 1, node->left);
		if (node->right)
			dfs(step + 1, node->right);
	}
}S;

int main()
{
	TreeNode *p0 = new TreeNode(0);
	TreeNode *p1 = new TreeNode(0);
	TreeNode *p2 = new TreeNode(0);
	TreeNode *p3 = new TreeNode(0);
	TreeNode *p4 = new TreeNode(0);
	TreeNode *p5 = new TreeNode(0);

	p0->left = p1;
	p0->right = p2;
	p1->left = p3;
	p1->right = p4;
	p4->right = p5;

	S.minDepth(p0);
	cout << S.minsize << endl;
	system("Pause");
}