//
// Created by 62339 on 2024/5/7.
//
#include <vector>
class cherry_pickup_ii {
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(m, 0)));
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= std::min(i, m - 1); ++j) {
                for (int k = m - 1; k >= std::max(0, m -1 - i); --k) {
                    for (int l = -1; l < 2; ++l) {
                        for (int i1 = -1; i1 < 2; ++i1) {
                            if (j + l >= 0 && j + l < m && i1+ k >= 0 && i1 + k < m) {
                                dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j + l][k + i1]);
                            }
                        }
                    }
                    dp[i][j][k] += j == k ? grid[i][j] : grid[i][j] + grid[i][k];
                }
            }
        }

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                result = std::max(result, dp[n - 1][i][j]);
            }
        }
        return result;
    }
};