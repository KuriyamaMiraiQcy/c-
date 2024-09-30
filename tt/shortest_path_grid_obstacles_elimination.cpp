//
// Created by 62339 on 2023/11/25.
//
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

class shortest_path_grid_obstacles_elimination {
public:
    int shortestPath(std::vector<std::vector<int>> &grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int visited[m][n][k + 1];
        std::memset(visited, false, sizeof(visited));
        visited[0][0][k] = true;

        std::queue<std::tuple<int, int, int>> queue;
        std::queue<int> step;
        queue.emplace(0, 0, k);
        step.emplace(0);

        auto is_valid = [&](int x, int y, int k) {
            return x >= 0 && y >= 0 && x < m && y < n && (grid[x][y] == 0 || (grid[x][y] == 1 && k > 0));
        };

        while (!queue.empty()) {
            auto top = queue.front();
            int x = get<0>(top), y = get<1>(top), z = get<2>(top);
            int s = step.front();
            step.pop();
            queue.pop();

            if (x == m - 1 && y == n - 1) {
                return s;
            }

            for (auto &dir: dirs) {
                if (is_valid(x + dir[0], y + dir[1], z)) {
                    int next_z = grid[x + dir[0]][y + dir[1]] > 0 ? z - 1 : z;
                    if (!visited[x + dir[0]][y + dir[1]][next_z]) {
                        visited[x + dir[0]][y + dir[1]][next_z] = true;
                        queue.emplace(x + dir[0], y + dir[1], next_z);
                        step.emplace(s + 1);
                    }
                }
            }
        }
        return -1;
    }

private:
    int dirs[4][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};

};