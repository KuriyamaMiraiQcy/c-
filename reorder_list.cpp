//
// Created by 62339 on 2023/10/7.
//
#include "Node.h"

class reorder_list {
public:
    void reorderList(ListNode *head) {
        ListNode dummy = ListNode(-1, head);
        ListNode *slow = &dummy, *fast = slow;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next != nullptr ? fast->next->next : fast->next;
        }

        fast = slow->next;
        slow->next = nullptr;
        slow = fast;
        while (slow != nullptr) {
            ListNode *temp = slow->next;
            slow->next = dummy.next;
            dummy.next = slow;
            slow = temp;
        }
        fast = dummy.next;
        slow = head;

        while (fast != head) {
            ListNode *temp = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            fast = temp;
            slow = slow->next->next;
        }
    }
};