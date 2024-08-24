#include <complex>
#include "../../TreeNode.h"

//
// Created by 62339 on 2023/10/30.
//
class balanced_binary_tree {
public:
    bool isBalanced(TreeNode* root) {
        traverse(root);
        return result;
    }
private:
    bool result = true;
    int traverse(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);

        if (std::abs(left - right) > 1) {
            result = false;
        }

        return std::max(left, right) + 1;
    }
};