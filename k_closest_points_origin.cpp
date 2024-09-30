//
// Created by 62339 on 2023/10/19.
//
#include <vector>
#include <algorithm>

class k_closest_points_origin {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k) {
        std::sort(points.begin(), points.end(), [](std::vector<int> a, std::vector<int> b) -> bool {
            return a[0] * a[0] + a[1] * a[1] - b[0] * b[0] - b[1] * b[1];
        });

        std::vector<std::vector<int>> result(k);
        for (int i = 0; i < k; ++i) {
            result.emplace_back(points[i]);
        }
        return result;
    }
};