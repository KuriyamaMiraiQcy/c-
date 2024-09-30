//
// Created by 62339 on 2023/8/20.
//
#include <vector>
#include <numeric>

class last_stone_weight2 {
public:
    int lastStoneWeightII(std::vector<int> &stones) {
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        std::vector<int> dp(target + 1);
        for (auto &stone: stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = std::max(dp[j - stone] + stone, dp[j]);
            }
        }
        return sum - 2 * dp[target];
    }
};