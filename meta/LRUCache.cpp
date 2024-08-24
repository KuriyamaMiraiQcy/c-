//
// Created by 62339 on 2023/10/27.
//
#include <unordered_map>
class LRUCache {
    struct double_linked_node {
        double_linked_node(int _val, int _key): val(_val), key(_key){};
        int val, key;
        double_linked_node* prev;
        double_linked_node* next;
    };
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        dummy = new double_linked_node(-1, -1);
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        double_linked_node* node = map[key];
        remove(node);
        add_to_front(node);
        return node->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key]->val = value;
            remove(map[key]);
            add_to_front(map[key]);
            return;
        }
        auto* node = new double_linked_node(value, key);
        add_to_front(node);
        map[key] = node;
        if (size < capacity) {
            ++size;
            return;
        }
        double_linked_node* n = dummy->prev;
        map.erase(n->key);
        remove(n);
        delete n;
    }

private:
    int capacity, size = 0;
    double_linked_node* dummy;
    std::unordered_map<int, double_linked_node*> map;

    void remove(double_linked_node* cur) {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }

    void add_to_front(double_linked_node* cur) {
        cur->next = dummy->next;
        dummy->next->prev = cur;
        dummy->next = cur;
        cur->prev = dummy;
    }
};
