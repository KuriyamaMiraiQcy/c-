//
// Created by 62339 on 2023/11/22.
//
#include <vector>
class spiral_matrix_ii {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int>(n , 0));
        int x = 0, y = 0;

        auto has_next = [&]()->bool {
            return x + directions[dir][0] >= 0 && x + directions[dir][0] < n && y + directions[dir][1] >= 0 &&
            y + directions[dir][1] < n && result[x + directions[dir][0]][y + directions[dir][1]] == 0;
        };

        for (int num = 1; num <= n * n; ++num) {
            result[x][y] = num;
            if (!has_next()) {
                dir = (dir + 1) % 4;
            }
            x += directions[dir][0];
            y += directions[dir][1];
        }

        return result;
    }
private:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0;
};