//
// Created by 62339 on 2023/8/17.
//
#include <vector>
#include "TreeNode.h"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <functional>

using namespace std;

class height_binary_tree_after_subtree_removal {
public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        unordered_map<int, vector<TreeNode *>> level;
        unordered_map<TreeNode *, int> deps;

        function<int(TreeNode *, int)> traverse_tree = [&](TreeNode *node, int l) -> int {
            if (!node) {
                return 0;
            }
            if (level.find(l) == level.end()) {
                level[l] = vector<TreeNode *>();
            }
            level[l].emplace_back(node);
            deps[node] = 1 + max(traverse_tree(node->left, l + 1), traverse_tree(node->right, l + 1));
            return deps[node];
        };
        int max_depth = traverse_tree(root, 0);

        unordered_map<int, int> res;
        
        function<void(TreeNode *, int)> dfs = [&](TreeNode *node, int l) -> void {
            if (!node) {
                return;
            }
            auto level_nodes = level[l];
            int max_depth = 0;
            for (auto &n: level_nodes) {
                if (n != node) {
                    max_depth = max(max_depth, deps[n]);
                }
            }
            res[node->val] = max_depth + l - 1;
            dfs(node->left, l + 1);
            dfs(node->right, l + 1);
        };
        dfs(root, 0);
        for (auto &query: queries) {
            query = res[query];
        }
        return queries;
    }
};