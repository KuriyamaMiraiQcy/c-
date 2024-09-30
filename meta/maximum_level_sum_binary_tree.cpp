#include "../../TreeNode.h"
#include <queue>
#include <vector>
#include <climits>

//
// Created by 62339 on 2023/10/30.
//
class maximum_level_sum_binary_tree {
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> queue;
        std::queue<int> levels;
        std::vector<int> sums;

        queue.emplace(root);
        levels.emplace(0);

        while (!queue.empty()) {
            TreeNode* top = queue.front();
            queue.pop();
            int level = levels.front();
            levels.pop();

            if (level == sums.size()) {
                sums.emplace_back(0);
            }
            sums[level] += top->val;

            if (top->left != nullptr) {
                queue.emplace(top->left);
                levels.emplace(level + 1);
            }
            if (top->right != nullptr) {
                queue.emplace(top->right);
                levels.emplace(level + 1);
            }
        }

        int l = 0;
        int max = INT_MIN;
        for (int i = 0; i < sums.size(); ++i) {
            if (sums[i] > max) {
                max = sums[i];
                l = i + 1;
            }
        }
        return l;
    }
};