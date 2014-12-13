#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		if (root == nullptr)
			return result;
		if (root->left == nullptr && root->right == nullptr)
		{
			result.push_back(root->val);
			return result;
		}
		stack<TreeNode *> s;
		TreeNode *ptr = root;
		while (1){
			while (ptr){
				s.push(ptr);
				ptr = ptr->left;
			}
			if (s.empty())
				break;
			ptr = s.top();
			result.push_back(ptr->val);
			s.pop();
			ptr = ptr->right;
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
	S.inorderTraversal(p1);
}