//
// Created by 62339 on 2023/10/30.
//
#include <vector>
#include <queue>
#include <unordered_set>
class shortest_path_binary_matrix {
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
        std::queue<std::tuple<int, int, int>> queue;
        if (grid[0][0] == 1) return -1;
        queue.emplace(0, 0, 1);
        std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid[0].size(), 0));
        visited[0][0] = 1;

        while (!queue.empty()) {
            int x = get<0>(queue.front());
            int y = get<1>(queue.front());
            int dis = get<2>(queue.front());
            queue.pop();
            if (x == grid.size() - 1 && y == grid[x].size() - 1) {
                return dis;
            }

            for (auto& direction:directions) {
                if (x + direction[0] >= 0 && x + direction[0] < grid.size() && y + direction[1] >= 0 &&
                y + direction[1] < grid[x].size() && grid[x + direction[0]][y + direction[1]] == 0 &&
                visited[x + direction[0]][y + direction[1]] == 0) {
                    visited[x + direction[0]][y + direction[1]] = 1;
                    queue.emplace(x + direction[0], y + direction[1], dis + 1);
                }
            }
        }
        return -1;
    }
private:
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1,1}};
};