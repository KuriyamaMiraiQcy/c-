//
// Created by 62339 on 2023/9/10.
//

#ifndef C___NODE_H
#define C___NODE_H


class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif //C___NODE_H
