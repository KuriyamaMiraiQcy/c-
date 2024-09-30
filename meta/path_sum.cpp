#include "../../TreeNode.h"

//
// Created by 62339 on 2023/10/26.
//
class path_sum {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        if (root->left != nullptr && hasPathSum(root->left, targetSum - root->val)) return true;
        return root->right != nullptr && hasPathSum(root->right, targetSum - root->val);
    }
};