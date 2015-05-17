//
// Created by zhengxx on 15/5/17.
//

/**
 * remove nth node from end of list
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * time = O(n), space = O(1)
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode h(1), *p = &h, *q = &h, *qre;
        p->next = head;
        while (n--)
            p = p->next;
        while (p) {
            p = p->next;
            qre = q;
            q = q->next;
        }
        qre->next = q->next;
        q->next = nullptr;
        delete q;
        return h.next;
    }
};