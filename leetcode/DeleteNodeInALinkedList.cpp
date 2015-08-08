//
// Created by zhengxx on 15/8/8.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == nullptr) return;
        node->val = node->next->val;
        ListNode *p = node->next;
        node->next = p->next;
        p->next = nullptr;
        delete p;
    }
};