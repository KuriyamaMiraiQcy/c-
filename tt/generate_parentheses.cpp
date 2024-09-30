//
// Created by 62339 on 2023/11/29.
//
#include <vector>
#include <string>
#include <functional>
class generate_parentheses {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::function<void(int, int, std::string&)> dfs = [&](int start, int end, std::string& s) {
            if (start == end && start == 0) {
                result.emplace_back(s);
                return;
            }
            if (end < start) {
                return;
            }
            if (start > 0) {
                s += "(";
                dfs(start - 1, end, s);
                s.pop_back();
            }
            if (end > 0) {
                s += ")";
                dfs(start, end - 1, s);
                s.pop_back();
            }
        };
        std::string s;
        dfs(n, n, s);
        return result;
    }
};