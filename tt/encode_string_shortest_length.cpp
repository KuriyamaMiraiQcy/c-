//
// Created by 62339 on 2023/11/23.
//
#include <string>
#include <vector>
class encode_string_shortest_length {
public:
    std::string encode(std::string s) {
        std::vector<std::vector<std::string>> dp(s.size(), std::vector<std::string>(s.size(), ""));

        auto compress = [&](int i, int j) {
            std::string sub = s.substr(i, j - i + 1);
            if (j - i < 4) {
                return sub;
            }
            int p = (sub + sub).find(sub, 1);
            if (p != sub.size()) {
                return std::to_string(sub.size() / p) + "[" + dp[i][i + p - 1] + "]";
            }
            return sub;
        };

        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0; i + len - 1 < s.size(); ++i) {
                int j = i + len - 1;
                dp[i][j] = compress(i, j);
                if (len > 4) {
                    for (int k = i; k < j; ++k) {
                        if (dp[i][j].size() > dp[i][k].size() + dp[k + 1][j].size()) {
                            dp[i][j] = dp[i][k] + dp[k + 1][j];
                        }
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};