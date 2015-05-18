//
// Created by zhengxx on 15/5/18.
//

/**
 * merge two sorted lists
 * https://leetcode.com/problems/merge-two-sorted-lists/
 * time = O(n + m), space = O(1)
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1), *p = &head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                p->next = l2;
                l2 = l2->next;
            }
            else {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head.next;
    }
};