//
// Created by 62339 on 2023/10/12.
//
#include <string>
#include <vector>

class minimum_insertion_steps_make_palindrome {
public:
    int minInsertions(std::string s) {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return s.size() - dp[0][s.size() - 1];
    }
};