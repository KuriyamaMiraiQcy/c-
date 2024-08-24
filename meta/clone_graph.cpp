//
// Created by 62339 on 2023/11/1.
//
#include "../../graph_node.h"
#include <unordered_map>
#include <functional>
class clone_graph {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        return copy(node);
    }
private:
    std::unordered_map<Node*, Node*> index;
    Node* copy(Node* n) {
        if (index.find(n) == index.end()) {
            index[n] = new Node(n->val);
        } else {
            return index[n];
        }

        for (auto& neighbor:n->neighbors) {
            index[n]->neighbors.emplace_back(copy(neighbor));
        }
        return index[n];
    }
};