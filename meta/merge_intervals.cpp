//
// Created by 62339 on 2023/8/27.
//
#include <vector>
#include <algorithm>

class merge_intervals {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        std::vector<std::vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = std::max(merged.back()[1], R);
            }
        }
        return merged;
    }
};