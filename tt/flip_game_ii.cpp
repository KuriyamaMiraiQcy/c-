//
// Created by 62339 on 2023/11/25.
//
#include <string>
#include <unordered_map>
class flip_game_ii {
public:
    bool canWin(std::string currentState) {
        return dfs(currentState, 1);
    }

private:
    bool is_end(std::string& s) {
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1] && s[i] == '+') {
                return false;
            }
        }
        return true;
    }
    std::unordered_map<std::string, int> memo;
    bool dfs(std::string& s, bool is_first) {
        if (is_end(s)) {
            memo[s] = !is_first;
            return !is_first;
        }
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        bool can_win = false;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == s[j + 1] && s[j] == '+') {
                s[j] = '-';
                s[j + 1] = '-';
                can_win |= is_first == dfs(s, !is_first);
                s[j] = '+';
                s[j + 1] = '+';
                if (can_win) break;
            }
        }
        memo[s] = can_win == is_first;
        return can_win == is_first;
    }
};