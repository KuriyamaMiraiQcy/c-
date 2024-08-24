//
// Created by 62339 on 2023/11/22.
//
#include <vector>
#include "../../Node.h"

class spiral_matrix_iv {
public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> result(m, std::vector<int>(n, -1));
        int x = 0, y = 0;

        auto has_next = [&]() -> bool {
            return x + dirs[dir][0] >= 0 && y + dirs[dir][1] >= 0 && x + dirs[dir][0] < m && y + dirs[dir][1] < n
            && result[x + dirs[dir][0]][y + dirs[dir][1]] == -1;
        };
        while (head != nullptr) {
            result[x][y] = head->val;
            head = head->next;
            if (!has_next()) {
                dir = (dir + 1) % 4;
            }
            x += dirs[dir][0];
            y += dirs[dir][1];
        }
        return result;
    }
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0;
};