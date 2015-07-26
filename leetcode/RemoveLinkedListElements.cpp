//
// Created by zhengxx on 15/7/26.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode Dummy(-1), *p = &Dummy;
        ListNode *q = head;
        p->next = q;
        while (q) {
            if (q->val == val) {
                p->next = q->next;
                q->next = nullptr;
                q = p->next;
            }
            else {
                p = q;
                q = q->next;
            }
        }
        return Dummy.next;
    }
};