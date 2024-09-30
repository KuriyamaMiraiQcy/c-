//
// Created by 62339 on 2023/11/29.
//
#include <vector>
#include <queue>
class rotting_oranges {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> queue;
        std::queue<int> time;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 2) {
                    queue.emplace(i, j);
                    time.emplace(0);
                }
            }
        }

        auto is_valid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < grid.size() && y < grid[x].size() && grid[x][y] == 1;
        };

        int result = 0;
        while (!queue.empty()) {
            int x = queue.front().first;
            int y = queue.front().second;
            int t = time.front();
            queue.pop();
            time.pop();
            result = std::max(result, t);

            for (auto& dir:dirs) {
                if (is_valid(x + dir[0], y + dir[1])) {
                    grid[x + dir[0]][y + dir[1]] = 2;
                    queue.emplace(x + dir[0], y + dir[1]);
                    time.emplace(t + 1);
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return result;
    }
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};