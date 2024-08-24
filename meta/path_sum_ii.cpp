//
// Created by 62339 on 2023/10/26.
//
#include <vector>
#include "../../TreeNode.h"

class path_sum_ii {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return result;
        }
        traverse(root, targetSum);
        return result;
    }
private:
    std::vector<std::vector<int>> result;
    std::vector<int> path;

    void traverse(TreeNode* root, int targetSum) {
        result.emplace_back(path);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                result.emplace_back(path);
            }
            path.pop_back();
            return;
        }

        if (root->left != nullptr) traverse(root->left, targetSum - root->val);
        if (root->right != nullptr) traverse(root->right, targetSum - root->val);
        path.pop_back();
    }
};