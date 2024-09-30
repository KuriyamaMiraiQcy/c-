//
// Created by 62339 on 2023/10/8.
//
#include <vector>

class spiral_matrix {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        int x = 0, y = 0;

        auto has_next = [&]() -> bool {
            return x + directions[direction][0] >= 0 && x + directions[direction][0] < matrix.size() &&
                   y + directions[direction][1] >= 0
                   && y + directions[direction][1] < matrix[0].size() &&
                   matrix[x + directions[direction][0]][y + directions[direction][1]] != 101;
        };

        std::vector<int> result(matrix.size() * matrix[0].size());
        int count = 0;
        while (count < result.size()) {
            result[count++] = matrix[x][y];
            matrix[x][y] = 101;
            if (!has_next()) {
                direction = (direction + 1) % 4;
            }
            x += directions[direction][0];
            y += directions[direction][1];
        }
        return result;
    }

private:
    const int directions[4][2] = {{0,  1},
                                  {1,  0},
                                  {0,  -1},
                                  {-1, 0}};
    int direction = 0;
};