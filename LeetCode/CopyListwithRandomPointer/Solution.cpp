#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(nullptr), random(nullptr){}
};

class Solution{
public:
	//O(n^2)
	
	RandomListNode *copyRandomList_1(RandomListNode *head)
	{
		if (head == nullptr) return nullptr;
		RandomListNode *root = new RandomListNode(head->label);
		RandomListNode *ptr = root;
		RandomListNode *p = head;
		while (p->next)
		{
			RandomListNode *temp = new RandomListNode(p->next->label);
			ptr->next = temp;
			p = p->next;
			ptr = temp;
		}
		ptr = root;
		p = head;
		RandomListNode *point = root;
		while (p)
		{
			int l;
			if (p->random == nullptr)
			{
				p = p->next;
				ptr = ptr->next;
				continue;
			}
			l = p->random->label;
			while (point)
			{
				if (point->label == l)
					break;
			}
			ptr->random = point;
			p = p->next;
			ptr = ptr->next;
			point = root;
		}
		return root;
	}

	//O(n) time£¬O(1) space
	
	RandomListNode *copyRandomList_2(RandomListNode *head)
	{
		if (head == nullptr) return nullptr;
		RandomListNode *root = new RandomListNode(head->label);
		root->next = head->next;
		head->next = root;
		RandomListNode *ptr = root;
		RandomListNode *p = ptr->next;
		while (p)
		{
			RandomListNode *temp = new RandomListNode(p->label);
			temp->next = p->next;
			p->next = temp;
			p = temp->next;
		}
		p = head;
		ptr = root;
		while (p){
			if (p->random == nullptr)
			{
				p = ptr->next;
				if (p == nullptr)
					break;
				ptr = p->next;
				continue;
			}
			ptr->random = p->random->next;
			p = ptr->next;
			if (p == nullptr)
				break;
			ptr = p->next;
		}
		p = head;
		ptr = root;
		while (p)
		{
			p->next = ptr->next;
			if (p->next == nullptr)
				break;
			ptr->next = p->next->next;
			p = p->next;
			ptr = ptr->next;
		}
		return root;
	}
	
	//hashmap
	RandomListNode *copyRandomList_3(RandomListNode *head)
	{
		if (head == nullptr) return head;
		unordered_map<RandomListNode *, RandomListNode *> um;
		RandomListNode* p1 = head;
		RandomListNode *root = new RandomListNode(head->label);
		RandomListNode* p2 = root;
		um[p1] = p2;
		p1 = p1->next;
		while (p1)
		{
			RandomListNode *temp = new RandomListNode(p1->label);
			p2->next = temp;
			um[p1] = temp;
			p2 = temp;
			p1 = p1->next;
		}
		p1 = head;
		p2 = root;
		while (p1)
		{
			if (p1->random)
				p2->random = um[p1->random];
			p1 = p1->next;
			p2 = p2->next;
		}
		return root;
	}
}S;


	
int main()
{
	RandomListNode *p = new RandomListNode(-1);
	RandomListNode *p1 = new RandomListNode(-1);
	p->next = p1;
	p->random = p1; 
	p1->random = p;
	S.copyRandomList_3(p);
}

