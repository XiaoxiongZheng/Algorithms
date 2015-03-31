#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
	void reorderList(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr) return;
		ListNode *headNode = new ListNode(0);
		headNode->next = head;
		ListNode *p = headNode;
		ListNode *q = headNode;
		while (q->next && q->next->next)
		{
			p = p->next;
			q = q->next->next;
		}
		//p = p->next;
		ListNode *new_head = p->next;
		p->next = nullptr;
		q = new_head->next;
		new_head->next = nullptr;
		while (q)
		{
			ListNode *_next = q->next;
			q->next = new_head;
			new_head = q;
			q = _next;
		}
		while (head->next && new_head->next)
		{
			ListNode *_next_head = head->next;
			ListNode *_next_new_head = new_head->next;
			head->next = new_head;
			new_head->next = _next_head;
			head = _next_head;
			new_head = _next_new_head;
		}
		head->next = new_head;
	}
}S;

int main()
{
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	ListNode *l3 = new ListNode(3);
	ListNode *l4 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	//l2->next = l3;
	S.reorderList(l1);
	while (l1){
		cout << l1->val << endl;
		l1 = l1->next;
	}
	system("Pause");
}

