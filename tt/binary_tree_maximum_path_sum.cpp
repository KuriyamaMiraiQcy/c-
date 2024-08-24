#include <algorithm>
#include "../../TreeNode.h"

//
// Created by 62339 on 2023/11/22.
//
class binary_tree_maximum_path_sum {
public:
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return result;
    }

    int traverse(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        result = std::max(result, left + right + root->val);
        result = std::max(result, left + root->val);
        result = std::max(result, right + root->val);
        return std::max(0, std::max(left + root->val, right + root->val));
    }
private:
    int result = INT_MIN;
};