//
// Created by 62339 on 2023/9/10.
//
#include "../../Node.h"

class copy_list_with_random_pointer {
public:
    Node *copyRandomList(Node *h) {
        if (h == nullptr) {
            return nullptr;
        }
        Node *head = h;
        while (head != nullptr) {
            auto *copy = new Node(head->val);
            copy->next = head->next;
            copy->random = head->random;
            auto *next = head->next;
            head->next = copy;
            head = next;
        }
        head = h;
        while (head != nullptr) {
            auto *copy = head->next;
            copy->random = copy->random != nullptr ? copy->random->next : nullptr;
            head = copy->next;
        }
        head = h;
        Node *result = h->next;
        while (head != nullptr) {
            Node *copy = head->next;
            head->next = copy->next;
            copy->next = copy->next != nullptr ? copy->next->next : nullptr;
            head = head->next;
        }
        return result;
    }
};