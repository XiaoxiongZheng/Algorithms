#include <iostream>
#include <stack>
using namespace std;


struct TreeNode
{
	int val; 
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root){
			s.push(root);
			root = root->right;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *node = s.top(), *subroot = s.top();
		s.pop();
		if (subroot->left)
		{
			subroot = subroot->left;
			while (subroot)
			{
				s.push(subroot);
				subroot = subroot->right;
			}
		}
		return node->val;
	}
private:
	stack<TreeNode *> s;
};
