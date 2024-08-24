//
// Created by 62339 on 2023/8/20.
//
struct DoubleLinkedListNode {
    DoubleLinkedListNode *prev;
    DoubleLinkedListNode *next;
    int val;

    DoubleLinkedListNode(int _val) : val(_val), prev(nullptr), next(nullptr) {}
};

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        capacity = k;
        count = 0;
        dummy = new DoubleLinkedListNode(-1);
        dummy->next = dummy;
        dummy->prev = dummy;
    }

    bool insertFront(int value) {
        if (count == capacity) {
            return false;
        }
        auto *node = new DoubleLinkedListNode(value);
        dummy->next->prev = node;
        node->next = dummy->next;
        node->prev = dummy;
        dummy->next = node;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (count == capacity) {
            return false;
        }
        auto *node = new DoubleLinkedListNode(value);
        dummy->prev->next = node;
        node->prev = dummy->prev;
        node->next = dummy;
        dummy->prev = node;
        count++;
        return true;
    }

    bool deleteFront() {
        if (count == 0) {
            return false;
        }
        dummy->next->next->prev = dummy;
        auto *node = dummy->next;
        dummy->next = dummy->next->next;
        delete node;
        count--;
        return true;
    }

    bool deleteLast() {
        if (count == 0) {
            return false;
        }
        dummy->prev->prev->next = dummy;
        auto *node = dummy->prev;
        dummy->prev = dummy->prev->prev;
        delete node;
        count--;
        return true;
    }

    int getFront() {
        if (count == 0) {
            return -1;
        }
        return dummy->next->val;
    }

    int getRear() {
        if (count == 0) {
            return -1;
        }
        return dummy->prev->val;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

private:
    int count;
    int capacity;
    DoubleLinkedListNode *dummy;
};