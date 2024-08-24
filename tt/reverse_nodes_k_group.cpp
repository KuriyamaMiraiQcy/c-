#include "../../Node.h"

//
// Created by 62339 on 2023/11/25.
//
class reverse_nodes_k_group {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1), *h = dummy, *t = h;
        int count = 0;
        while (head != nullptr) {
            ListNode* temp = head->next;
            if (count == 0) {
                t->next = head;
                h = t;
                t= head;
                h->next = nullptr;
            }
            head->next = h->next;
            h->next = head;
            count = (count + 1) % k;
            head = temp;
        }
        if (count != 0) {
            h->next = reverseKGroup(h->next, count);
        }
        return dummy->next;
    }
};