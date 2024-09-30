#include "../../TreeNode.h"

//
// Created by 62339 on 2023/10/30.
//
class merge_two_binary_trees {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        int val1 = root1 == nullptr?0:root1->val;
        int val2 = root2 == nullptr?0:root2->val;
        TreeNode* node = new TreeNode(val1 + val2, mergeTrees(root1==nullptr?nullptr:root1->left, root2==nullptr?nullptr:root2->left), mergeTrees(root1==nullptr?nullptr:root1->right, root2==nullptr?nullptr:root2->right));
        return node;
    }
};