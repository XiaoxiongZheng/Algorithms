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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		if (l1 == NULL && l2 == NULL)
			return NULL;

		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *node = new ListNode(0);
		ListNode *p3 = node;

		bool carry = false;

		while (p1!=NULL && p2!=NULL)
		{
			int temp = p1->val + p2->val;
			if (carry)
				temp++;
			if (temp >= 10)
				carry = true;
			else
				carry = false;
			ListNode *newNode = new ListNode(temp%10);
			p1 = p1->next;
			p2 = p2->next;
			p3->next = newNode;
			p3 = newNode;
		}
		while (p1!=NULL)
		{
			int temp = p1->val;
			if (carry)
				temp++;
			if (temp >= 10)
				carry = true;
			else
				carry = false;
			ListNode *newNode = new ListNode(temp%10);
			p1 = p1->next;
			p3->next = newNode;
			p3 = newNode;
		}

		while (p2!=NULL)
		{
			int temp = p2->val;
			if (carry)
				temp++;
			if (temp >= 10)
				carry = true;
			else
				carry = false;
			ListNode *newNode = new ListNode(temp%10);
			p2 = p2->next;
			p3->next = newNode;
			p3 = newNode;
		}
		if (carry)
		{
			ListNode *newNode = new ListNode(1);
			p3->next = newNode;
		}

		return node->next;
	}
};

int main()
{
	ListNode *l1 = new ListNode(9);
	ListNode *l2 = new ListNode(0);
	ListNode *l3 = new ListNode(1);
	ListNode *l4 = new ListNode(6);
	l1->next = l3;
	l3->next = l4;
	ListNode *head;
	Solution s;
	head = s.addTwoNumbers(l1, l2);
	while(head!=NULL){
		cout<<head->val<<"\t";
		head = head->next;
	}
	system("Pause");
	return 0;
}