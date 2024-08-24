//
// Created by 62339 on 2023/9/23.
//
#include <vector>

class super_egg_drop {
public:
    int superEggDrop(int k, int n) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

        for (int i = 1; i <= k; ++i) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i - 1][k];
            }
            if (dp[i][k] >= n) {
                return i;
            }
        }
        return 1;
    }
};