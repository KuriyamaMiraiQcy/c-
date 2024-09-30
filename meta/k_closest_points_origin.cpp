//
// Created by 62339 on 2023/11/2.
//
#include <vector>
#include <algorithm>
#include <queue>

class k_closest_points_origin {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) -> bool{
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1]*b[1];
        });

        std::vector<std::vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(points[i]);
        }
        return result;
    }

    std::vector<std::vector<int>> kClosest1(std::vector<std::vector<int>>& points, int k) {
        auto cmp = [](std::vector<int> a, std::vector<int> b) -> bool{
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1]*b[1];
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmp)> pq;

        for (int i = 0; i < points.size(); ++i) {
            if (i < k) {
                pq.emplace(points[i]);
                continue;
            }
            if (cmp(points[i], pq.top())) {
                pq.pop();
                pq.emplace(points[i]);
            }
        }
        std::vector<std::vector<int>> result(k);

        for (int i = k - 1; i >= 0; --i) {
            result[i] = pq.top();
            pq.pop();
        }
        return result;
    }
};