//
// Created by 62339 on 2023/11/1.
//
#include <vector>
#include "../../TreeNode.h"
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <queue>

class nodes_distance_k_binary_tree {
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map<TreeNode*, std::vector<TreeNode*>> map;

        std::function<TreeNode*(TreeNode*)> traverse = [&](TreeNode* root) -> TreeNode* {
            if (root->left == nullptr && root->right == nullptr) {
                return root;
            }
            if (root->left != nullptr) {
                map[root].emplace_back(root->left);
                map[traverse(root->left)].emplace_back(root);
            }
            if (root->right != nullptr) {
                map[root].emplace_back(root->right);
                map[traverse(root->right)].emplace_back(root);
            }
            return root;
        };

        traverse(root);
        std::queue<TreeNode*> queue;
        std::queue<int> dis;
        queue.emplace(target);
        dis.emplace(0);
        std::unordered_set<TreeNode*> visited;
        visited.emplace(target);
        std::vector<int> result;

        while (!queue.empty()) {
            if (dis.front() > k) { break;}
            if (dis.front() == k) {
                result.emplace_back(queue.front()->val);
            }
            for (auto& n:map[queue.front()]) {
                if (visited.find(n) == visited.end()) {
                    queue.emplace(n);
                    visited.emplace(n);
                    dis.emplace(dis.front() + 1);
                }
            }
            queue.pop();
            dis.pop();
        }

        return result;
    }
};