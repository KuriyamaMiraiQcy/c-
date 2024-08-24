#include "../../TreeNode.h"
#include <vector>
#include <climits>

//
// Created by 62339 on 2023/11/28.
//
class largest_bst_subtree {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root);
        return result;
    }

private:
    int result = 1;
    std::vector<int> dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val, root->val, 1};
        }
        std::vector<int> left, right;

        bool is_valid = true;
        if (root->left != nullptr) {
            left = dfs(root->left);
            if (root->val <= left[1]) {
                is_valid = false;
            }
        }
        if (root->right != nullptr) {
            right = dfs(root->right);
            if (root->val >= right[0]) {
                is_valid = false;
            }
        }
        if (!is_valid) {
            return {INT_MIN, INT_MAX, -1};
        }
        int size = 1 + (left.size() == 0 ? 0 : left[2]) + (right.size() == 0 ? 0 : right[2]);
        result = std::max(result, size);
        return {left.empty() ? root->val : left[0], right.empty() ? root->val : right[1], size};
    }
};