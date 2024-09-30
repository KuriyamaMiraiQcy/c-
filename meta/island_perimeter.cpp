//
// Created by 62339 on 2023/11/3.
//
#include <vector>
#include <functional>
#include <iostream>

class island_perimeter {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        auto is_valid = [&](int x, int y) -> bool {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
        };
        std::function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (grid[x][y] == 0) {
                return 0;
            }
            int result = 0, count = 0;
            grid[x][y] = -1;
            if (x == 0) {++count;}
            if (x == grid.size() - 1) {++count;}
            if (y == 0) {++count;}
            if (y == grid[x].size() - 1) {++count;}
            for (auto& dir:directions) {
                if (is_valid(x + dir[0], y + dir[1])) {
                    if (grid[x + dir[0]][y + dir[1]] == 1) {
                        result += dfs(x + dir[0], y + dir[1]);
                    }
                    count += grid[x + dir[0]][y + dir[1]] == 0;
                }
            }
            return count > 0? result + 1: result;
        };

        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    result = std::max(result, dfs(i, j));
                }
            }
        }
        return result;
    }
private:
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

//int main() {
//    island_perimeter a;
//    std::vector<std::vector<int>> t({{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}});
//    std::cout << a.islandPerimeter(t) << std::endl;
//    std::vector<std::vector<int>> t1({{1}});
//    std::cout << a.islandPerimeter(t1) << std::endl;
//    std::vector<std::vector<int>> t2({{1, 0}});
//    std::cout << a.islandPerimeter(t2) << std::endl;
//}