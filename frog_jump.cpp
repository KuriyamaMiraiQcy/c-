//
// Created by 62339 on 2023/10/12.
//
#include <vector>

class frog_jump {
public:
    bool canCross(std::vector<int> &stones) {
        std::vector<std::vector<int>> dp(stones.size(), std::vector<int>(stones.size(), 0));
        dp[1][1] = stones[1] == 1;
        for (int i = 2; i < stones.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int dis = stones[i] - stones[j];

                if (dis > j + 1) break;
                dp[i][dis] = dp[j][dis - 1] || dp[j][dis] || dp[j][dis + 1];
            }
        }

        for (int i = 0; i < stones.size(); ++i) {
            if (dp[stones.size() - 1][i]) {
                return true;
            }
        }
        return false;
    }
};