#include <climits>
#include <algorithm>
#include "../../TreeNode.h"

//
// Created by 62339 on 2023/11/1.
//
class minimum_depth_binary_tree {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int left = root->left == nullptr?INT_MAX:minDepth(root->left);
        int right = root->right == nullptr?INT_MAX:minDepth(root->right);

        return std::min(left, right) + 1;
    }
};