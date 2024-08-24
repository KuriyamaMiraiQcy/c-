//
// Created by 62339 on 2023/10/19.
//
#include "../../TreeNode.h"

class range_sum_bst {
public:
    int rangeSumBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return 0;
        int sum = root->val >= low && root->val <= high ? root->val : 0;
        sum += root->val <= low ? 0 : rangeSumBST(root->left, low, high);
        sum += root->val >= high ? 0 : rangeSumBST(root->right, low, high);
        return sum;
    }
};