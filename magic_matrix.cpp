//
// Created by 62339 on 2023/8/21.
//
#include <iostream>
#include <vector>

class magic_matrix {
public:
    void output_matrix() {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> result(n, std::vector<int>(n));
        int row = 0, col = n / 2;
        for (int i = 1; i <= n * n; ++i) {
            result[row][col] = i;
            if (row == 0 && col == n - 1) {
                ++row;
                continue;
            }
            if (row == 0 && col < n - 1) {
                row = n - 1;
                ++col;
                continue;
            }
            if (row != 0 && col == n - 1) {
                --row;
                col = 0;
                continue;
            }
            if (result[(row + n) % (n + 1)][(col + 1) % (n + 1)] == 0) {
                row = (row + n) % (n + 1);
                col = (col + 1) % (n + 1);
                continue;
            }
            ++row;
        }
        for (int i = 0; i < result.size(); ++i) {
            for (int j = 0; j < result.size(); ++j) {
                std::cout << result[i][j] << std::endl;
            }
        }
    }
};
