//
// Created by 62339 on 2023/10/31.
//
#include <string>
#include <vector>
#include <stack>
class minimum_remove_make_valid_parentheses {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::stack<int> open;
        std::vector<int> index(s.size(), 0);

        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == '(') {
                open.push(i);
            }
            if (s[i] == ')') {
                if (open.empty()) {
                    index[i] = 1;
                } else {
                    open.pop();
                }
            }
        }

        while (!open.empty()) {
            index[open.top()] = 1;
            open.pop();
        }

        std::string result;
        for (int i = 0; i < s.size(); ++i) {
            if (index[i] == 0) {
                result += s[i];
            }
        }
        return result;
    }
};