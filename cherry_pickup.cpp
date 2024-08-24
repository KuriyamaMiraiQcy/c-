//
// Created by 62339 on 2024/5/7.
//
#include <vector>
class cherry_pickup {
public:
    int cherryPickup(std::vector<std::vector<int>> &grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -10000));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n * 2 - 1; ++i) {
            for (int j = std::min(i, n - 1); j >= std::max(0, i - n + 1); --j) {
                for (int k = std::min(i, n - 1); k >= j; --k) {
                    int y_1 = i - j, y_2 = i - k;
                    if (grid[j][y_1] == -1 || grid[k][y_2] == -1) {
                        dp[j][k] = -10000;
                        continue;
                    }
                    if (j > 0) {
                        dp[j][k] = std::max(dp[j - 1][k], dp[j][k]);
                    }
                    if (k > 0) {
                        dp[j][k] = std::max(dp[j][k - 1], dp[j][k]);
                    }
                    if (j > 0 && k > 0) {
                        dp[j][k] = std::max(dp[j][k], dp[j - 1][k - 1]);
                    }
                    dp[j][k] += grid[j][y_1] + (j == k ? 0 : grid[k][y_2]);
                }
            }
        }
        return std::max(dp[n - 1][n - 1], 0);
    }
};