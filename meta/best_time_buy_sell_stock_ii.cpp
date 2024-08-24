//
// Created by 62339 on 2023/10/31.
//
#include <vector>
class best_time_buy_sell_stock_ii {
public:
    int maxProfit(std::vector<int>& prices) {
        int nothing = 0, hold = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            int n_nothing = std::max(nothing, hold + prices[i]);
            int n_hold = std::max(nothing - prices[i], hold);
            nothing = n_nothing;
            hold = n_hold;
        }

        return nothing;
    }
};