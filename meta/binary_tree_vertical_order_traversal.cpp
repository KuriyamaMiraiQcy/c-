//
// Created by 62339 on 2023/10/29.
//
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include "../../TreeNode.h"

class binary_tree_vertical_order_traversal {
public:
    std::vector<std::vector<int>> verticalOrder(TreeNode *root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }
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
        std::stable_sort(pos.begin(), pos.end(), [](auto &a, auto &b) -> bool {
            return get<0>(a) == get<0>(b) ? get<1>(a) < get<1>(b) : get<0>(a) < get<0>(b);
        });

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