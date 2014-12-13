#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		if (root->left == nullptr && root->right == nullptr)
		{
			result.push_back(root->val);
			return result;
		}
		TreeNode *ptr = root;
		stack<TreeNode *> s;
		s.push(ptr);
		while (1)
		{
			if (s.empty())
				break;
			ptr = s.top();
			s.pop();
			result.push_back(ptr->val);
			if (ptr->right)
				s.push(ptr->right);
			if (ptr->left)
				s.push(ptr->left);

		}
		return result;
	}

}S;

int main()
{
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	p1->right = p2;
	p2->left = p3;
	S.preorderTraversal(p1);
}