//
// Created by 62339 on 2023/8/26.
//
#include <vector>

class unique_binary_search_trees {
public:
    int numTrees(int n) {
        dp = std::vector<int>(19, 0);
        dp[0] = 1;
        return calculate(n);
    }

private:
    std::vector<int> dp;

    int calculate(int n) {
        if (n <= 1) {
            return 1;
        }
        if (dp[n - 1] != 0) {
            return dp[n - 1];
        }
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += calculate(i - 1) * calculate(n - i);
        }
        dp[n - 1] = result;
        return result;
    }
};