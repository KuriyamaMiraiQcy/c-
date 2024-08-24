//
// Created by 62339 on 2023/11/25.
//
#include <vector>
#include <climits>

class best_time_buy_sell_stock_iii {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy_1 = INT_MIN, sell_1 = 0, buy_2 = INT_MIN, sell_2 = 0;

        for (auto& price:prices) {
            sell_2 = std::max(sell_2, buy_2 + price);
            buy_2 = std::max(buy_2, sell_1 - price);
            sell_1 = std::max(sell_1, buy_1 + price);
            buy_1 = std::max(buy_1, -price);
        }
        return sell_2;
    }
};