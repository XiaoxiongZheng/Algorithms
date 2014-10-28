#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};
class Solution{
private:
	struct cmp{
		bool operator () (const ListNode *p1, const ListNode *p2)
		{
			return p1->val > p2->val;
		}
	};
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		if (lists.size() == 0)
			return NULL;
		ListNode *head = new ListNode(0);
		
		ListNode *p = head;
		priority_queue<ListNode *, vector<ListNode *>, cmp> q;
		for (int i = 0; i < lists.size(); i++)
			if (lists[i])
				q.push(lists[i]);

		while (!q.empty())
		{
			head->next = q.top();
			q.pop();
			head = head->next;
			if (head->next)
				q.push(head->next);
		}
		return p->next;
	}
}S;

int main()
{
	ListNode *L1 = new ListNode(0);
	ListNode *L2 = new ListNode(1);
	ListNode *L3 = new ListNode(2);
	ListNode *L4 = new ListNode(3);
	ListNode *L5 = new ListNode(4);
	ListNode *L6 = new ListNode(5);
	ListNode *L7 = new ListNode(6);
	ListNode *L8 = new ListNode(7);
	ListNode *L9 = new ListNode(8);
	ListNode *L10 = new ListNode(9);
	ListNode *L11 = new ListNode(10);
	ListNode *L12 = new ListNode(11);
	ListNode *L13 = new ListNode(12);

	L1->next = L3;
	L3->next = L5;
	L5->next = L7;
	L7->next = L9;
	L9->next = L11;
	L11->next = L13;
	L2->next = L4;
	L4->next = L6;
	L6->next = L8;
	L8->next = L10;
	L10->next = L12;

	vector<ListNode *> vec;
	vec.push_back(L1);
	vec.push_back(L2);
	ListNode *p = S.mergeKLists(vec);
	while (p){
		cout << p->val << endl;
		p = p->next;
	}
	system("Pause");
}