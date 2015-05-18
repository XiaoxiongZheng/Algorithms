//
// Created by zhengxx on 15/5/18.
//

/**
 * swap nodes in pairs
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 * time = O(n), space = O(1)
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return head;
        ListNode Dummy(-1), *pre = &Dummy;
        pre->next = head;
        ListNode *q = head, *p = head->next;
        while(p){
            ListNode *n = p->next;
            pre->next = p;
            q->next = n;
            p->next = q;
            if (n && n->next) {
                pre = q;
                q = n;
                p = n->next;
            }
            else
                break;
        }
        return Dummy.next;
    }
};