//
// Created by 62339 on 2023/10/20.
//
#include "TreeNode.h"
#include <functional>
class find_distance_in_binary_tree {
public:
    int findDistance(TreeNode* root, int p, int q) {
        int result = 0;
        std::function<int(TreeNode*)> find = [&](TreeNode* root) -> int {
            if (root == nullptr) {
                return 0;
            }
            if (root->val == p || root->val == q) {
                return 1;
            }

            int left = find(root->left);
            int right = find(root->right);

            if (left > 0 && right > 0) {
                result = left + right - 2;
                return result;
            }
            return left + right;
        };

        find(root);
        return result;
    };
};