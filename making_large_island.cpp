//
// Created by 62339 on 2023/10/18.
//
#include <vector>
#include <functional>
#include <unordered_map>
#include <unordered_set>

class making_large_island {
public:
    int largestIsland(std::vector<std::vector<int>> &grid) {
        int index = 2;
        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            grid[i][j] = index;
            int result = 1;
            for (auto &dir: directions) {
                if (i + dir[0] >= 0 && i + dir[0] < grid.size() && j + dir[1] >= 0 && j + dir[1] < grid[i].size() &&
                    grid[i + dir[0]][j + dir[1]] == 1) {
                    result += dfs(i + dir[0], j + dir[1]);
                }
            }
            return result;
        };

        int result = 0;
        std::unordered_map<int, int> count;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    count.emplace(index, dfs(i, j));
                    result = std::max(result, count[index]);
                    ++index;
                }
            }
        }


        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> dir;
                    int num = 1;
                    for (int k = 0; k < 4; ++k) {
                        if (i + directions[k][0] >= 0 && i + directions[k][0] < grid.size() &&
                            j + directions[k][1] >= 0 && j + directions[k][1] < grid[i].size() &&
                            grid[i + directions[k][0]][j + directions[k][1]] != 0 &&
                            dir.find(grid[i + directions[k][0]][j + directions[k][1]]) == dir.end()) {
                            dir.emplace(grid[i + directions[k][0]][j + directions[k][1]]);
                            num += count[grid[i + directions[k][0]][j + directions[k][1]]];
                        }
                    }

                    result = std::max(result, num);
                }
            }
        }
        return result;
    }

private:
    int directions[4][2] = {{0,  1},
                            {0,  -1},
                            {1,  0},
                            {-1, 0}};
};