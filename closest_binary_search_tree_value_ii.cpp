//
// Created by 62339 on 2024/5/9.
//
#include <vector>
#include <bits/stdc++.h>
#include "TreeNode.h"
class closest_binary_search_tree_value_ii {
public:
    std::vector<int> closestKValues(TreeNode* root, double target, int k) {
        traverse(root);

        int start = 0, end = arr.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        start--;
        std::vector<int> result;
        while (k != 0) {
            k--;
            if (start < 0) {
                result.emplace_back(arr[end++]);
                continue;
            }
            if (end >= arr.size()) {
                result.emplace_back(arr[start--]);
                continue;
            }
            if (target - arr[start] > arr[end] - target) {
                result.emplace_back(arr[end++]);
            } else {
                result.emplace_back(arr[start--]);
            }

        }
        return result;
    }
private:
    std::vector<int> arr;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left);
        arr.emplace_back(root->val);
        traverse(root->right);
    }
};