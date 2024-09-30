#include "../../Node.h"

//
// Created by 62339 on 2023/11/23.
//
class sort_linked_list_sorted_using_absolute_values {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode *n_head = nullptr, *n_tail = nullptr;
        ListNode *po_head = nullptr, *po_tail = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            if (head->val >= 0) {
                if (po_head == nullptr) {
                    po_head = head;
                    po_tail = head;
                } else {
                    po_tail->next = head;
                    po_tail = head;
                }
                head->next = nullptr;
            } else {
                if (n_head == nullptr) {
                    n_head = head;
                    n_tail = head;
                } else {
                    head->next = n_head;
                    n_head = head;
                }
            }
            head = temp;
        }
        if (n_tail != nullptr) {
            n_tail->next = po_head;
        }
        return n_head;
    }
};