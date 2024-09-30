//
// Created by 62339 on 2023/10/19.
//
#include "Node.h"

class palindrome_linked_list {
public:
    bool isPalindrome(ListNode *head) {
        if (head->next == nullptr) { return true; }

        ListNode *fast = head->next, *low = head;
        while (fast != nullptr && fast->next != nullptr) {
            low = low->next;
            fast = fast->next->next;
        }

        ListNode dummy(-1), *temp = low;
        low = low->next;
        temp->next = nullptr;

        while (low != nullptr) {
            ListNode *next = low->next;
            low->next = dummy.next;
            dummy.next = low;
            low = next;
        }

        auto recover = [&]() {
            ListNode *re = dummy.next;
            while (re != nullptr) {
                ListNode *next = re->next;
                re->next = temp->next;
                temp->next = re;
                re = next;
            }
        };
        ListNode *compare = dummy.next;
        while (compare != nullptr) {
            if (head->val != compare->val) {
                recover();
                return false;
            }
            head = head->next;
            compare = compare->next;
        }

        recover();
        return true;
    }
};