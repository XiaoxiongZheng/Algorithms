//
// Created by zhengxx on 15/5/17.
//

/**
 * reverse linked list
 * https://leetcode.com/problems/reverse-linked-list/
 * time = O(n), space = O(1)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* p = head->next;
        head->next = nullptr;
        while (p)
        {
            ListNode* n = p->next;
            p->next = head;
            head = p;
            p = n;
        }
        return head;
    }
};