//
// Created by 62339 on 2024/5/14.
//
#include <vector>
class perfect_squares {
public:
    int numSquares(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i ; ++j) {
                dp[i] = std::min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};