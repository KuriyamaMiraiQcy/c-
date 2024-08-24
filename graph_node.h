//
// Created by 62339 on 2023/11/1.
//

#ifndef C___GRAPH_NODE_H
#define C___GRAPH_NODE_H
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


#endif //C___GRAPH_NODE_H
