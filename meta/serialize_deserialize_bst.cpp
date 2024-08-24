//
// Created by 62339 on 2023/11/2.
//
#include <string>
#include "../../TreeNode.h"
#include <functional>

class serialize_deserialize_bst {
public:
    std::string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        if (root->left == nullptr && root->right == nullptr) {
            return std::to_string(root->val);
        }
        std::string result;
        if (root->left != nullptr) result += serialize(root->left) + ",";
        if (root->right != nullptr) result += serialize(root->right) + ",";
        result += std::to_string(root->val);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::vector<int> nums;
        std::string s;
        for (char i : data + ",") {
            if (isalnum(i)) {
                s += i;
            } else {
                if (!s.empty()) {
                    nums.emplace_back(stoi(s));
                }
                s = "";
            }
        }
        std::function<TreeNode*(int, int)> recover = [&](int start, int end) -> TreeNode* {
            if (start > end) {
                return nullptr;
            }
            auto* n = new TreeNode(nums[end]);
            int i = end - 1;
            for (; i >= start; --i) {
                if (nums[i] < nums[end]) {
                    break;
                }
            }
            n->left = recover(start, i);
            n->right = recover(i + 1, end - 1);
            return n;
        };

        return recover(0, nums.size() - 1);
    }

};