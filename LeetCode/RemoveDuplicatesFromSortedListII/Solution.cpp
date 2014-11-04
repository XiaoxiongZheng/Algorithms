#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode *head)
	{
		if (head == nullptr)
			return nullptr;
		if (head->next == nullptr)
			return head;
		ListNode *h = new ListNode(head->val - 1);
		h->next = head;
		ListNode *pre = h;
		ListNode *p = head->next;
		while (p)
		{
			if (pre->next->val == p->val)
			{
				p = p->next;
				continue;
			}
			else {
				if (pre->next->next != p)
				{
					pre->next = p;
					p = p->next;
				}
				else {
					pre = pre->next;
					p = p->next;
				}
			}
		}
		if (pre->next && pre->next->next)
			pre->next = nullptr;
		return h->next;
	}
}; S;

int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	p1->next = p3;
	p3->next = p2;
	ListNode *r = S.deleteDuplicates(p1);
	if (r)
		cout << r->val << endl;
	system("Pause");
}