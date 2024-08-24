#include "../../Node.h"
#include <vector>
#include <queue>
//
// Created by 62339 on 2023/11/1.
//
class merge_k_sorted_lists {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) -> bool {
            return a->val > b->val;
        };

        if (lists.size() == 0) {
            return nullptr;
        }

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> pq;
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        for (auto& list:lists) {
            if (list != nullptr) {
                pq.emplace(list);
            }
        }

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            if (top->next != nullptr) {
                pq.emplace(top->next);
            }
            top->next = nullptr;
            tail->next = top;
            tail = tail->next;
        }
        return dummy.next;
    }
};