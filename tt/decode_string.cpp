//
// Created by 62339 on 2023/11/24.
//
#include <string>
#include <stack>
class decode_string {
public:
    std::string decodeString(std::string s) {
        std::stack<std::string> stack;

        auto is_num = [](char s) {
            return s >= '0' && s <= '9';
        };

        auto is_letter = [](char s) {
            return s >= 'a' && s <= 'z';
        };

        for (auto& ch:s) {
            if (ch == '[') {
                stack.push("[");
                continue;
            }
            if (is_num(ch)) {
                if (!stack.empty() && is_num(stack.top()[0])) {
                    stack.top() += ch;
                } else {
                    stack.emplace(1, ch);
                }
                continue;
            }
            if (is_letter(ch)) {
                if (!stack.empty() && is_letter(stack.top()[0])) {
                    stack.top() += ch;
                } else {
                    stack.emplace(1, ch);
                }
                continue;
            }
            std::string recon;
            while (stack.top() != "[") {
                recon = stack.top() + recon;
                stack.pop();
            }
            stack.pop();
            int n = stoi(stack.top());
            stack.pop();

            std::string new_top;
            for (int i = 0; i < n; ++i) {
                new_top += recon;
            }
            stack.push(new_top);
        }

        std::string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};