#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		return judge(p, q);
	}
	bool judge(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;
		if ((p && !q) || (!p && q))
			return false;
		if (p->val != q->val)
			return false;
		return judge(p->left, q->left) && judge(p->right, q->right);
	}
};