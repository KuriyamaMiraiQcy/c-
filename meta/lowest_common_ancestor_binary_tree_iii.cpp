
#include <unordered_set>
#include "../../TreeNode.h"

//
// Created by 62339 on 2023/10/28.
//
class lowest_common_ancestor_binary_tree_iii {
public:
    TreeNode* lowestCommonAncestor(TreeNode* p, TreeNode * q) {
        std::unordered_set<TreeNode*> parents;
        while (p != nullptr) {
            parents.emplace(p);
            p = p->parent;
        }

        while (q!= nullptr) {
            if (parents.find(q) != parents.end()) {
                return q;
            }
            q = q->parent;
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor1(TreeNode* p, TreeNode * q) {
        TreeNode *p1 = p, *p2 = q;
        while (p1 != p2) {
            p1 = p1 == nullptr ? q : p1->parent;
            p2 = p2 == nullptr ? p : p2->parent;
        }
        return p1;
    }
};