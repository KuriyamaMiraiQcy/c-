//
// Created by 62339 on 2023/10/12.
//
#include <string>
#include <vector>
#include <unordered_set>

class word_break {
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        std::vector<int> dp(s.size() + 1);
        dp[0] = 1;

        std::unordered_set<std::string> dict;
        for (std::string s: wordDict) {
            dict.emplace(s);
        }

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] |= dp[j];
                }
            }
        }
        return dp[dp.size() - 1];
    }
};