//
// Created by 62339 on 2023/10/25.
//
#include <functional>
#include <string>
class punishment_number {
public:
    bool dfs(std::string &s, int pos, int tot, int target) {
        if (pos == s.size()) {
            return tot == target;
        }
        int sum = 0;
        for (int i = pos; i < s.size(); i++) {
            sum = sum * 10 + s[i] - '0';
            if (sum + tot > target) {
                break;
            }
            if (dfs(s, i + 1, sum + tot, target)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            std::string s = std::to_string(i * i);
            if (dfs(s, 0, 0, i)) {
                res += i * i;
            }
        }
        return res;
    }
};