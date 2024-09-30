//
// Created by 62339 on 2023/11/2.
//
#include <string>
#include <vector>
class palindromic_substrings {
public:
    int countSubstrings(std::string s) {
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

        dp[s.size() - 1][s.size() - 1] = 1;
        int result = 1;
        for (int i = s.size() - 2; i >= 0; --i) {
            dp[i][i] = 1;
            ++result;
            for (int j = i + 1; j < s.size(); ++j) {
                dp[i][j] = s[i] == s[j] && (((i + 1 < j) && dp[i + 1][j - 1]) || i == j - 1);
                result += dp[i][j];
            }
        }
        return result;
    }
};