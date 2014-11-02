#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	vector<TreeNode *> generateTrees(int n)
	{
		if (n < 1)
		{
			vector<TreeNode *> vec;
			vec.push_back(nullptr);
			return vec;
		}
		vector<TreeNode *> result = dfs(1, n);
		return result;
	}
	vector<TreeNode *> dfs(int start, int end)
	{
		vector<TreeNode *> result;
		if (start > end)
			//push nullptr is to increase a element in result, if not this, when the root's left/right subtree is null, the loop will not execute!
			result.push_back(nullptr);
			
		for (int i = start; i <= end; i++)
		{
			//this is critical, store the left subtree and right subtree
			vector<TreeNode *> leftSide = dfs(start, i-1);
			vector<TreeNode *> rightSide = dfs(i + 1, end);
			for (int k = 0; k < leftSide.size(); k++)
				for (int j = 0; j < rightSide.size(); j++)
				{
					TreeNode *p = new TreeNode(i);
					p->left = leftSide[k];
					p->right = rightSide[j];
					result.push_back(p);
				}
		}
		return result;
	}
}S;

int main()
{
	vector<TreeNode *> vec = S.generateTrees(0);
	cout << vec.size() << endl;
	system("Pause");
}