//
// Created by 62339 on 2023/11/25.
//
#include <vector>
#include <climits>

class best_time_buy_sell_stock_iv {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        std::vector<std::vector<int>> dp(k, {INT_MIN, 0});

        for (auto& price:prices) {
            for (int i =  k - 1; i > 0; --i) {
                dp[i][1] = std::max(dp[i][1], dp[i][0] + price);
                dp[i][0] = std::max(dp[i - 1][1] - price, dp[i][0]);
            }
            dp[0][1] = std::max(dp[0][1], dp[0][0] + price);
            dp[0][0] = std::max(dp[0][0], -price);
        }
        return dp[k - 1][1];
    }
};