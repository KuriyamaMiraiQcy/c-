//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class longest_increasing_path_matrix {
private:
    std::vector<std::vector<int>> dp;
    int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
public:
    int longestIncreasingPath(std::vector<std::vector<int>> &matrix) {
        dp = std::vector<std::vector<int>>(matrix.size(), std::vector<int>(matrix[0].size(), 0));

        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                result = std::max(result, dp[i][j]?dp[i][j]:dfs(matrix, i, j));
            }
        }
        return result;
    }

    int dfs(std::vector<std::vector<int>> &matrix, int i, int j) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        int result = 0;
        for (auto &direction:directions) {
            if (i + direction[0] >= 0 && i + direction[0] < matrix.size() && j + direction[1] >= 0
                && j + direction[1] < matrix[0].size() && matrix[i + direction[0]][j + direction[1]] > matrix[i][j]) {
                result = std::max(result, dfs(matrix, i + direction[0], j + direction[1]));
            }
        }
        dp[i][j] = std::max(1, result + 1);
        return dp[i][j];
    }
};