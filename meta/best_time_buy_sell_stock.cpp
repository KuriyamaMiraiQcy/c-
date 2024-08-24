//
// Created by 62339 on 2023/10/31.
//
#include <vector>
class best_time_buy_sell_stock {
public:
    int maxProfit(std::vector<int>& prices) {
        int result = 0, min = prices[0];

        for (auto& p:prices) {
            result = std::max(result, p - min);
            min = std::min(min, p);
        }

        return result;
    }
};