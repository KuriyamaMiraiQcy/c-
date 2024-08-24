//
// Created by 62339 on 2023/10/8.
//
#include <vector>
#include <string>

class regular_expression_matching {
public:
    bool isMatch(std::string s, std::string p) {
        std::vector<std::vector<bool>> dp(s.size() + 1, std::vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= p.size(); j += 2)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j] || dp[i][j - 2];
                    char prev = p[j - 2];
                    dp[i][j] = ((prev == '.' || s[i - 1] == prev) && dp[i - 1][j]) || dp[i][j];
                    continue;
                }
                dp[i][j] = ((p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1]) || dp[i][j];
            }
        }
        return dp[s.size()][p.size()];
    }
};