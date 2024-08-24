//
// Created by 62339 on 2023/11/28.
//
#include <vector>
#include <stack>
class daily_temperatures {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> dec;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!dec.empty() && temperatures[dec.top()] < temperatures[i]) {
                result[dec.top()] = i - dec.top();
                dec.pop();
            }
            dec.emplace(i);
        }
        return result;
    }
};