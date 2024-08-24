//
// Created by 62339 on 2023/11/27.
//
#include <vector>
#include <unordered_set>
#include <functional>
class permutations {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<int> used(nums.size(), 0);

        std::vector<std::vector<int>> result;
        std::vector<int> res;

        std::function<void()> dfs = [&]() {
            if (res.size() == nums.size()) {
                result.emplace_back(res);
                return;
            }
            for (int i = 0; i < nums.size(); ++i) {
                if (!used[i]) {
                    res.emplace_back(nums[i]);
                    used[i] = 1;
                    dfs();
                    used[i] = 0;
                    res.pop_back();
                }
            }
        };

        dfs();
        return result;
    }
};