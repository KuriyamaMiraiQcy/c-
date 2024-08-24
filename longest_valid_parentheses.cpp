//
// Created by 62339 on 2023/9/4.
//
#include <string>
#include <stack>

class longest_valid_parentheses {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> unpaired, paired;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                unpaired.push(i);
                continue;
            }
            if (!unpaired.empty()) {
                int top = unpaired.top();
                paired.push(top);
                unpaired.pop();
            } else {
                unpaired.push(-1);
            }
        }

        int count = 0, result = 0;
        while (!paired.empty()) {
            int top = paired.top();
            if (unpaired.empty() || (top > unpaired.top() && unpaired.top() != -1)) {
                count += 2;
                result = std::max(result, count);
                paired.pop();
                continue;
            }
            result = std::max(result, count);
            count = 0;
            if (!unpaired.empty()) unpaired.pop();
        }
        return result;
    }
};