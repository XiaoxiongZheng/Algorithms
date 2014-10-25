#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

//class Solution
//{
//public:
//	int maxPathSum(TreeNode *root)
//	{
//		if (root == NULL)
//			return 0;
//		return sum(root);
//	}
//	int sum(TreeNode *root)
//	{
//		if (root->left == NULL && root->right == NULL)
//			return root->val;
//		int sumLeft;
//		int sumRight;
//		if (root->left && root->right == NULL){
//			sumLeft = sum(root->left);
//			int result = max(sumLeft, root->val);
//			return max(result, sumLeft + root->val);
//		}
//		if (root->right && root->left == NULL){
//			sumRight = sum(root->right);
//			int result = max(sumRight, root->val);
//			return max(result, sumRight + root->val);
//		}
//		sumLeft = sum(root->left);
//		sumRight = sum(root->right);
//		if (root->val < 0)
//		{
//			if (sumLeft < 0 && sumRight < 0)
//			{
//				int result = max(root->val, sumLeft);
//				return max(result, sumRight);
//			}
//			if (sumLeft < 0)
//			{
//				return sumRight;
//			}
//			if (sumRight < 0)
//			{
//				return sumLeft;
//			}
//			return max(sumLeft, sumRight);
//		}
//		if (sumLeft < 0 && sumRight < 0)
//		{
//			return root->val;
//		}
//		if (sumLeft < 0)
//		{
//			return root->val + sumRight;
//		}
//		if (sumRight < 0)
//		{
//			return root->val + sumLeft;
//		}
//		return sumLeft + sumRight + root->val;
//	}
//}S;
class Solution {
public:
	int maxresult = INT_MIN;

	int maxSum(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int value = root->val;
		int leftValue = maxSum(root->left);
		int rightValue = maxSum(root->right);
		if (leftValue > 0)
			value += leftValue;
		if (rightValue > 0)
			value += rightValue;
		maxresult = max(maxresult, value);
		return (max(leftValue, rightValue) > 0 ? max(leftValue, rightValue) + root->val : root->val);
	}

	int maxPathSum(TreeNode *root) {
		if (!root)
			return 0;
		maxSum(root);
		return maxresult;
	}

}S1;
int main()
{
	TreeNode *root = new TreeNode(1);
	TreeNode *l = new TreeNode(-2);
	TreeNode *r = new TreeNode(-3);
	TreeNode *ll = new TreeNode(-2);
	TreeNode *lr = new TreeNode(-4);
	TreeNode *rl = new TreeNode(-3);
	TreeNode *rll = new TreeNode(3);
	root->left = l;
	root->right = r;
	l->left = ll;
	l->right = lr;
	r->left = rl;
	rl->left = rll;
	cout << S1.maxPathSum(root);
	system("Pause");
	return 0;
}