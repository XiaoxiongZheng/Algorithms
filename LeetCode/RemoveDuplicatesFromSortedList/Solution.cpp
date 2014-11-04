#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
	ListNode* deleteDuplicates(ListNode *head)
	{
		if (head == nullptr)
			return nullptr;
		ListNode *h = new ListNode(head->val - 1);
		ListNode *pre = h;
		ListNode *p = head;
		while (p)
		{
			if (p->val == pre->val)
				p = p->next;
			else if (pre->next != p)
			{
				pre->next = p;
				pre = p;
				p = p->next;
			}
			else
			{
				pre = pre->next;
				p = p->next;
			}
		}
		pre->next = nullptr;
		return h->next;
	}

};