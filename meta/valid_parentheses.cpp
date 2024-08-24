//
// Created by 62339 on 2023/11/1.
//
#include <string>
#include <stack>
#include <unordered_map>
class valid_parentheses {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        std::unordered_map<char, char> pairs = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };

        for (auto& ch: s) {
            if (pairs.find(ch) != pairs.end()) {
                if (stack.empty() || stack.top() != pairs[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.emplace(ch);
            }
        }
        return stack.empty();
    }
};