#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x):label(x){}
};

class Solution{
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (node == 0)
			return 0;
		map<int, UndirectedGraphNode *> m;
		queue<UndirectedGraphNode *> q;
		q.push(node);
		while(!q.empty())
		{
			UndirectedGraphNode *r = q.front();
			q.pop();
			if(m.find(r->label) == m.end())
			{
				UndirectedGraphNode *n = new UndirectedGraphNode(r->label);
				m.insert(pair<int, UndirectedGraphNode *>(n->label, n));
				for(int i = 0; i<r->neighbors.size(); i++)
					q.push(r->neighbors[i]);
			}
		}
		q.push(node);
		while (!q.empty())
		{
			UndirectedGraphNode *r = q.front();
			q.pop();
			UndirectedGraphNode *newNode = m[r->label];
			if (newNode->neighbors.empty() && !r->neighbors.empty())
			{
				for (int i = 0; i<r->neighbors.size(); i++){
					newNode->neighbors.push_back(m[r->neighbors[i]->label]);
					q.push(r->neighbors[i]);
				}		
			}
				
		}
		return m[node->label];
	}
}S;

int main()
{

}