//
// Created by 62339 on 2023/8/20.
//
#include "TreeNode.h"
#include <vector>

class is_subStructure {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        if (!A || !B) {
            return false;
        }
        return is_equal(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool is_equal(TreeNode *A, TreeNode *B) {
        if (!B) {
            return true;
        }
        if (!A || A->val != B->val) {
            return false;
        }
        return is_equal(A->left, B->left) && is_equal(A->right, B->right);
    }
};