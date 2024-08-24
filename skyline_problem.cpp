//
// Created by 62339 on 2023/10/15.
//
#include <vector>
#include <queue>
#include <bits/stdc++.h>

class skyline_problem {
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>> &buildings) {
        auto cmp = [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
            return a.second < b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

        std::vector<int> scan_line;

        for (auto &building: buildings) {
            scan_line.emplace_back(building[0]);
            scan_line.emplace_back(building[1]);
        }
        std::sort(scan_line.begin(), scan_line.end());

        int index = 0;
        std::vector<std::vector<int>> result;
        for (auto &line: scan_line) {
            while (index < buildings.size() && buildings[index][0] < line) {
                pq.emplace(buildings[index][1], buildings[index][2]);
                ++index;
            }

            while (!pq.empty() && pq.top().first < line) {
                pq.pop();
            }

            int height = pq.empty() ? 0 : pq.top().second;
            if (result.empty() || result.back()[1] != height) {
                result.emplace_back(line, height);
            }
        }
        return result;
    }
};