//
// Created by 62339 on 2023/10/20.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class custom_sort_string {
public:
    std::string customSortString(std::string order, std::string s) {
        std::unordered_map<char, int> count;
        for (int i = 0; i < order.size(); ++i) {
            count[order[i]] = i;
        }

        std::vector<int> num;
        for (int i = 0; i < s.size(); ++i) {
            if (count.find(order[i]) == count.end()) {
                num.emplace_back(i+999);
            } else {
                num.emplace_back(count[order[i]]);
            }
        }

        std::sort(num.begin(), num.end());
        std::string result;

        for (int i : num) {
            result += i < order.size() ? order[i] : order[i - 999];
        }

        return result;
    }
};