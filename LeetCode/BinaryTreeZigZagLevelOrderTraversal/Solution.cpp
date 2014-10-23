#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{

public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		queue<TreeNode *> q;
		vector<int> r;
		vector<vector<int> > result;

		if(root == 0)
			return result;

		if(root->left == 0 && root->right == 0){
			r.push_back(root->val);
			result.push_back(r);
			return result;
		}
		q.push(root);
		int count = 0;
		while(!q.empty())
		{
			TreeNode *start = q.front();
			count++;
			bool index = true;
			if (start->left == 0 && start->right == 0)
				index = false;

			vector<int> level;
			while(!q.empty() && start->left != q.front() && start->right != q.front()){
				
				TreeNode *p = q.front();
				level.push_back(p->val);
				if (p->left)
				{
					if (!index){
						start = p;
						index = true;
					}
					q.push(p->left);
				}
				if (p->right){
					if (!index){
						start = p;
						index = true;
					}
					q.push(p->right);
				}
				q.pop();
			}
			if( count % 2 == 0)
			{
				vector<int> vec;
				for(vector<int>::reverse_iterator iter = level.rbegin(); iter != level.rend(); iter++)
					vec.push_back(*iter);
				result.push_back(vec);
				continue;
			}
			result.push_back(level);
		}
		return result;
	}
}S;


int main()
{
	TreeNode *l1= new TreeNode(3);
	TreeNode *l2= new TreeNode(9);
	TreeNode *l3= new TreeNode(20);
	TreeNode *l4= new TreeNode(15);
	TreeNode *l5= new TreeNode(7);

	l1->left = l2;
	l1->right = l3;
	l3->left = l4;
	l3->right = l5;

	vector<vector<int> > r;
	r = S.zigzagLevelOrder(l1);
	vector<vector<int> >::iterator iter= r.begin();
	for(; iter!=r.end(); iter++)
	{
		vector<int>::iterator vtr = iter->begin();
		for(; vtr != iter->end(); vtr++)
			cout<<*vtr<<"\t";
		cout<<endl;
	}
	system("Pause");
}