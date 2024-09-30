//
// Created by 62339 on 2023/8/18.
//
#include <vector>
#include <unordered_set>
#include "../../TreeNode.h"

using namespace std;

class delete_nodes_return_forest {
public:
    vector<TreeNode *> ans;
    unordered_set<int> s;

    TreeNode *dfs(TreeNode *node) {
        if (node == nullptr) return nullptr;
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        if (s.find(node->val) == s.end()) return node;
        if (node->left) ans.push_back(node->left);
        if (node->right) ans.push_back(node->right);
        return nullptr;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (int x: to_delete) s.insert(x);
        if (dfs(root)) ans.push_back(root);
        return ans;
    }
};