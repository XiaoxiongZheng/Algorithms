#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution
{
public:
	ListNode *swapPairs(ListNode *head){
		ListNode *h= (ListNode *)malloc(sizeof(ListNode));
		h->next = head;
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		
		ListNode *pre = h;
		ListNode *ptr = pre->next;
		ListNode *tail = ptr->next;

		while ( true )
		{
			pre->next = tail;
			ptr->next = tail->next;
			tail->next = ptr;
			pre = ptr;
			if (ptr->next)
				ptr = ptr->next;
			else
				break;
			if (ptr->next)
				tail = ptr->next;
			else
				break;
		}
		return h->next;
	}
};

int main(void)
{
	ListNode *l1;
	l1 = (ListNode *)malloc(sizeof(ListNode));
	l1->val = 1;
	ListNode *l2= (ListNode *)malloc(sizeof(ListNode));
	l2->val = 2;
	ListNode *l3= (ListNode *)malloc(sizeof(ListNode));
	l3->val = 3;
	ListNode *l4= (ListNode *)malloc(sizeof(ListNode));
	l4->val = 4;
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = NULL;

	Solution s;
	l1 = s.swapPairs(l1);
}