//
// Created by 62339 on 2023/11/22.
//
#include <vector>
class spiral_matrix_iii {
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int count = 1, step = 1;
        std::vector<std::vector<int>> result;
        result.push_back({rStart, cStart});

        while (count < rows * cols) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < step; ++j) {
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];

                    if (rStart >= 0 && cStart >= 0 && rStart < rows && cStart < cols) {
                        result.push_back({rStart, cStart});
                        ++count;
                    }
                }
                direction = (direction + 1) % 4;
            }
            ++step;
        }
        return result;
    }
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direction = 0;
};