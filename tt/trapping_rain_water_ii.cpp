//
// Created by 62339 on 2023/11/26.
//
#include <vector>
#include <queue>
class trapping_rain_water_ii {
public:
    int trapRainWater(std::vector<std::vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
        auto cmp = [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq;
        for (int i = 0; i < m; ++i) {
            pq.emplace(heightMap[i][0], i * n);
            visited[i][0] = 1;
            pq.emplace(heightMap[i][n - 1], i * n + n - 1);
            visited[i][n - 1] = 1;

            if (i == 0 || i == m - 1) {
                for (int j = 1; j < n - 1; ++j) {
                    pq.emplace(heightMap[i][j], i * n + j);
                    visited[i][j] = 1;
                }
            }
        }

        auto is_valid = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n && !visited[x][y];
        };

        int result = 0;
        while (!pq.empty()) {
            int x = pq.top().second / n;
            int y = pq.top().second % n;

            for (auto& dir:dirs) {
                if (is_valid(x + dir[0], y + dir[1])) {
                    result += std::max(pq.top().first, heightMap[x + dir[0]][y + dir[1]]) - heightMap[x + dir[0]][y + dir[1]];
                    visited[x + dir[0]][y + dir[1]] = 1;
                    pq.emplace(std::max(pq.top().first, heightMap[x + dir[0]][y + dir[1]]), (x + dir[0]) * n + y + dir[1]);
                }
            }
            pq.pop();
        }

        return result;
    }
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};