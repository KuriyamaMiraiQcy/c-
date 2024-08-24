//
// Created by 62339 on 2023/11/2.
//
#include <unordered_map>

class LFUCache {
private:
    int size;
    int count = 0;
    int min_freq = 0;

    struct DoubleLinkedNode {
        int val;
        int key;
        int freq;

        DoubleLinkedNode *prev;
        DoubleLinkedNode *next;

        DoubleLinkedNode(int _val, int _key, int _freq) : val{_val}, key{_key}, freq{_freq} {};
    };

    std::unordered_map<int, DoubleLinkedNode *> freq_map;
    std::unordered_map<int, DoubleLinkedNode *> key_map;

    void remove(DoubleLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void add_back(DoubleLinkedNode *node, DoubleLinkedNode *front) {
        node->prev = front->prev;
        node->next = front;
        front->prev->next = node;
        front->prev = node;
    }

    void increase_freq(DoubleLinkedNode *node) {
        if (node->prev == node) {
            freq_map.erase(node->freq);
        } else {
            if (freq_map[node->freq] == node) {
                freq_map[node->freq] = node->next;
            }
            remove(node);
        }
        ++node->freq;
        if (freq_map.find(node->freq) == freq_map.end()) {
            freq_map[node->freq] = node;
            node->prev = node;
            node->next = node;
        } else {
            add_back(node, freq_map[node->freq]);
        }
        if (freq_map.find(min_freq) == freq_map.end()) {
            ++min_freq;
        }
    }

public:
    LFUCache(int capacity) {
        size = capacity;
    }

    int get(int key) {
        if (key_map.find(key) == key_map.end()) {
            return -1;
        }
        increase_freq(key_map[key]);
        return key_map[key]->val;
    }

    void put(int key, int value) {
        if (key_map.find(key) != key_map.end()) {
            increase_freq(key_map[key]);
            key_map[key]->val = value;
        } else {
            ++count;
            if (count > size) {
                DoubleLinkedNode *node = freq_map[min_freq];
                if (node->prev == node) {
                    freq_map.erase(min_freq);
                    key_map.erase(node->key);
                    node->prev = nullptr;
                    node->next = nullptr;
                    delete node;
                    while (!freq_map.empty() && freq_map.find(min_freq) == freq_map.end()) {
                        ++min_freq;
                    }
                    if (freq_map.empty()) {
                        min_freq = 0;
                    }
                } else {
                    DoubleLinkedNode *next = node->next;
                    remove(node);
                    freq_map[min_freq] = next;
                    key_map.erase(node->key);
                    delete node;
                }
                --count;
            }
            auto *n = new DoubleLinkedNode(value, key, 1);
            key_map[key] = n;
            min_freq = 1;
            if (freq_map.find(1) == freq_map.end()) {
                freq_map[1] = n;
                n->prev = n;
                n->next = n;
            } else {
                add_back(n, freq_map[1]);
            }
        }
    }
};

//int main() {
//    LFUCache a(2);
//    a.put(2, 2);
//    a.put(1, 1);
//    a.get(1);
//    a.put(3, 3);
//    a.get(2);
//    a.get(3);
//    a.put(4, 4);
//    a.get(1);
//    a.get(3);
//    a.get(4);
//}