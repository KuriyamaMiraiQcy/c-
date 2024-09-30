//
// Created by 62339 on 2023/10/17.
//
#include <vector>
#include "../../TreeNode.h"
#include <functional>

class vertical_order_traversal_binary_tree {
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode *root) {
        std::vector<std::tuple<int, int, int>> pos;

        std::function<void(TreeNode *, int, int)> traverse = [&](TreeNode *root, int col, int row) -> void {
            if (root == nullptr) {
                return;
            }
            pos.emplace_back(col, row, root->val);
            traverse(root->left, col - 1, row + 1);
            traverse(root->right, col + 1, row + 1);
        };

        traverse(root, 0, 0);
        std::sort(pos.begin(), pos.end());
        std::vector<std::vector<int>> result;
        result.emplace_back(1, get<2>(pos[0]));

        int index = 0;
        for (int i = 1; i < pos.size(); ++i) {
            if (get<0>(pos[i]) == get<0>(pos[i - 1])) {
                result.back().emplace_back(get<2>(pos[i]));
            } else {
                result.emplace_back(1, get<2>(pos[i]));
            }
        }
        return result;
    }
};