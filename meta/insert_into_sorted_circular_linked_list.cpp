#include "../../Node.h"

//
// Created by 62339 on 2023/10/31.
//
class insert_into_sorted_circular_linked_list {
public:
    Node* insert(Node* head, int insertVal) {
        auto is_valid = [&](Node* head) -> bool {
            bool result = false;

            result |= head->val < insertVal && insertVal <= head->next->val;
            result |= insertVal <= head->next->val && head ->val > head->next->val;
            result |= head->val < insertVal && head ->val > head->next->val;
            return result;
        };

        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* temp = head;
        while (temp->next != head) {
            if (is_valid(temp)) {
                break;
            }
            temp = temp->next;
        }

        temp->next = new Node(insertVal, temp->next);
        return head;
    }
};