//
// Created by 62339 on 2023/11/28.
//
#include <string>
#include <vector>
class remove_k_digits {
public:
    std::string removeKdigits(std::string num, int k) {
        std::vector<char> stack;

        for (int i = 0; i < num.size(); ++i) {
            while (!stack.empty() && k > 0 && num[i] < stack.back()) {
                stack.pop_back();
                k--;
            }
            stack.emplace_back(num[i]);
        }

        while (k > 0) {
            stack.pop_back();
            --k;
        }

        std::string result;

        bool start_zero = true;
        for (char i : stack) {
            if (i == '0' && start_zero) {
                continue;
            }
            start_zero = false;
            result += i;
        }
        return result.empty() ? "0" : result;
    }
};