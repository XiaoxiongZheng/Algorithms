//
// Created by zhengxx on 15/5/18.
//

/**
 * reverse nodes in k-group
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 * time = O(n), space = O(1)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode Dummy(-1), *p = &Dummy, *h;
        p->next = head;
        while(p){
            int cnt = k;
            h = p;
            while (cnt && p->next){
                p = p->next;
                cnt--;
            }
            if (cnt > 0) break;
            ListNode *n = p->next, *t = h->next;
            p->next = nullptr;
            h->next = reverse(t);
            t->next = n;
            p = t;
        }
        return Dummy.next;
    }

    ListNode* reverse(ListNode* head){
        if (head == nullptr) return head;
        ListNode *p = head->next;
        head->next = nullptr;
        while(p){
            ListNode* n = p->next;
            p->next = head;
            head = p;
            p = n;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k < 2) return head;
        ListNode *p = head;
        for (int i = 0; i < k; i++)
        {
            if(p)
                p = p->next;
            else
                return head;
        }
        ListNode *new_p = reverseKGroup(p, k);
        ListNode *prev = nullptr, *cur = head;
        while(cur != p)
        {
            ListNode *next = cur->next;
            cur->next = prev ? prev : new_p;
            prev = cur;
            cur =next;
        }
        return prev;
    }
};