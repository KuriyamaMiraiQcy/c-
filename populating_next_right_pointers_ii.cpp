//
// Created by 62339 on 2023/11/3.
//
#include <queue>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
class populating_next_right_pointers_ii {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        std::queue<Node*> queue;
        std::queue<int> level;
        queue.emplace(root);
        level.emplace(0);

        while (!level.empty()) {
            Node* top = queue.front();
            int l = level.front();
            queue.pop();
            level.pop();

            if (!level.empty() && level.front() == l) {
                top->next = queue.front();
            }

            if (top->left != nullptr) {
                queue.push(top->left);
                level.push(l + 1);
            }
            if (top->right != nullptr) {
                queue.push(top->right);
                level.push(l + 1);
            }
        }
        return root;
    }
};