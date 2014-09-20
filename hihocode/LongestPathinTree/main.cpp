#include <iostream>
using namespace std;

const int MAXEDGE = 100001;
int x = 0;

struct edge{
	int val;
	edge *next;
	bool index;
	edge()
	{
		index = false;
		next = 0;
	}
}e[MAXEDGE];

int dp(int u, int v)
{

}
int main()
{
	int edgeNum;
	cin>>edgeNum;
	int u, v;
	while(cin>>u>>v)
	{
		if (e[u].index)
		{
			edge *p = e[u].next;
			while(p->next != NULL)
				p = p->next;
			p->next = new edge();
			p->val = v;
			continue;
		}
		e[u].val = u;
		e[u].next = new edge();
		e[u].val = v;
	}
}