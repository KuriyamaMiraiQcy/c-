#include <utility>
#include "../../TreeNode.h"

//
// Created by 62339 on 2023/10/27.
//
class smallest_subtree_with_all_deepest_nodes {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }

private:
    std::pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {root, 0};
        }
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if (l.second == r.second) {
            return {root, l.second + 1};
        }
        if (l.second > r.second) {
            return {l.first, l.second + 1};
        }
        return {r.first, r.second + 1};
    }
};