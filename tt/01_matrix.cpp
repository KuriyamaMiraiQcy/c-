#include <vector>
#include <queue>
//
// Created by 62339 on 2023/11/26.
//
class zero_matrix {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat) {
        std::queue<std::pair<int, int>> queue;
        std::queue<int> dis;
        std::vector<std::vector<int>> visited(mat.size(), std::vector<int>(mat[0].size(), -1));

        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 0) {
                    queue.emplace(i, j);
                    dis.emplace(0);
                    visited[i][j] = 0;
                }
            }
        }

        auto is_valid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < mat.size() && y < mat[x].size();
        };

        while (!queue.empty()) {
            int x = queue.front().first, y = queue.front().second, d = dis.front();
            queue.pop();
            dis.pop();

            for (auto& dir:dirs) {
                if (is_valid(x + dir[0], y + dir[1]) && visited[x + dir[0]][y + dir[1]] == -1) {
                    visited[x + dir[0]][y + dir[1]] = d + 1;
                    queue.emplace(x + dir[0], y + dir[1]);
                    dis.emplace(d + 1);
                }
            }
        }
        return visited;
    }

private:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};