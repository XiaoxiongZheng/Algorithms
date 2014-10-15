#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(0){}
};

class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		if (head == NULL)
			return 0;
		
		ListNode *h = new ListNode(0);
		h->next = head;
		ListNode *p = h;
		ListNode *pos = h;
		
		for( int i = 0; i < n; i++ )
			p = p->next;

		while(p->next)
		{
			p = p->next;
			pos = pos->next;
		}

		ListNode *pre = pos;
		pos = pos->next;

		pre->next = pos->next;
		pos->next = 0;
		delete pos;
		return h->next;
	}
}S;

int main()
{
	ListNode *L[5];
	for (int i = 1; i <= 5; i++)
		L[i-1] = new ListNode(i);
	for (int i = 0; i<4; i++)
		L[i] ->next = L[i+1];
	S.removeNthFromEnd(L[0], 2);
	ListNode *p = L[0];
	while(p){
		cout<<p->val<<endl;
		p = p->next;
	}
	system("Pause");
}