#include "../../TreeNode.h"

//
// Created by 62339 on 2023/11/1.
//
class sum_root_leaf_numbers {
public:
    int sumNumbers(TreeNode* root) {
        traverse(root, 0);
        return result;
    }

    void traverse(TreeNode* root, int value) {
        int res = value * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            result += res;
            return;
        }
        if (root->left != nullptr) traverse(root->left, res);
        if (root->right != nullptr) traverse(root->right, res);
    }
private:
    int result = 0;
};