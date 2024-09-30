//
// Created by 62339 on 2023/11/24.
//
#include <string>
#include <vector>
class edit_distance {
public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word2.size(); ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};