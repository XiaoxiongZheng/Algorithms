//
// Created by zhengxx on 15/5/18.
//

#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

struct cmp{
    bool operator () (const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        int len = lists.size();
        for (int i = 0; i < len; i++)
            if (lists[i]) pq.push(lists[i]);
        ListNode Dummy(-1), *p = &Dummy;
        while (!pq.empty()){
            ListNode *q = pq.top();
            pq.pop();
            p->next = q;
            if(q->next) pq.push(q->next);
            p = p->next;
        }
        return Dummy.next;
    }
};