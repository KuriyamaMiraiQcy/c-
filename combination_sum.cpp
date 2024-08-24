//
// Created by 62339 on 2023/10/25.
//
#include <vector>
#include <unordered_map>
#include <functional>
class combination_sum {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> cur;
        std::vector<std::vector<int>> result;
        std::function<void(int, int)> dfs = [&](int index, int total) {
            if (total == target) {
                result.emplace_back(cur);
                return;
            }
            if (index == candidates.size() || total > target) {
                return;
            }
            cur.emplace_back(candidates[index]);
            dfs(index, total + candidates[index]);
            cur.pop_back();
            dfs(index + 1, total);
        };

        dfs(0, 0);
        return result;
    }
};