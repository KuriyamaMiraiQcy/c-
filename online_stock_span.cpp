//
// Created by 62339 on 2023/10/7.
//
#include <stack>
#include <cmath>

class StockSpanner {
public:
    StockSpanner() {
        stack.emplace(-1, INT_MAX);
    }

    int next(int price) {
        int result = 1;
        day++;
        while (!stack.empty() && stack.top().second <= price) {
            result = std::max(result, day - stack.top().first);
            stack.pop();
        }
        stack.emplace(day, price);
        return result;
    }

private:
    std::stack<std::pair<int, int>> stack;
    int day = 0;
};