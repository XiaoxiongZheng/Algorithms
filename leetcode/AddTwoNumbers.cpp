//
// Created by zhengxx on 15/5/14.
//


/**
 * add two numbers
 * https://leetcode.com/problems/add-two-numbers/
 * time = O(m + n), space = O(m + n)
 */

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode Dummy(-1), *h = &Dummy;
        int flag = 0;
        for (; l1 || l2 || flag;)
        {
            if(l1) flag += l1->val, l1 = l1->next;
            if(l2) flag += l2->val, l2 = l2->next;
            ListNode *p = new ListNode(flag % 10);
            h->next = p, h = p, flag = flag / 10;
        }
        return Dummy.next;
    }
};
