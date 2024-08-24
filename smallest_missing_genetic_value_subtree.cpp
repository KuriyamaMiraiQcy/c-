//
// Created by 62339 on 2023/10/31.
//
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>
class smallest_missing_genetic_value_subtree {
public:
    std::vector<int> smallestMissingValueSubtree(std::vector<int>& parents, std::vector<int>& nums) {
        int index = std::find(nums.begin(), nums.end(), 1) - nums.begin();
        std::vector<int> result(nums.size(), 0);
        if (index == nums.size()) {
            return std::vector<int>(nums.size(), 1);
        }

        std::vector<std::vector<int>> graph(nums.size());
        for (int i = 1; i < parents.size(); ++i) {
            graph[parents[i]].emplace_back(i);
        }

        int missing = 1;
        std::unordered_set<int> reached;
        std::function<void(int)> dfs = [&](int parent) {
            result[parent] = 1;
            for (auto& child:graph[parent]) {
                if (result[child] == 0) {
                    dfs(child);
                }
            }
            reached.emplace(nums[parent]);
        };

        while (index != -1) {
            dfs(index);
            while (reached.find(missing) != reached.end()) {
                ++missing;
            }
            result[index] = missing;
            index = parents[index];
        }
        return result;
    }
};