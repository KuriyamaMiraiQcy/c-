#include "../../TreeNode.h"

//
// Created by 62339 on 2023/10/27.
//
#include <vector>
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        nums = std::vector<int>();
        traverse(root);
    }

    int next() {
        int result = nums[cur++];
        return result;
    }

    bool hasNext() {
        return cur < nums.size();
    }
private:
    std::vector<int> nums;
    int cur = 0;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left);
        nums.emplace_back(root->val);
        traverse(root->right);
    }
};