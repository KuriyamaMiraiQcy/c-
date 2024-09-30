//
// Created by 62339 on 2023/10/31.
//
#include <vector>
class interval_list_intersections {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> result;

        int first = 0, second = 0;
        while (first < firstList.size() && second < secondList.size()) {
            if (!is_disjoint(firstList[first], secondList[second])) {
                result.emplace_back(join(firstList[first], secondList[second]));
            }
            if (firstList[first][1] < secondList[second][1]) {
                first++;
            } else {
                second++;
            }
        }
        return result;
    }
private:
    bool is_disjoint(std::vector<int> a, std::vector<int> b) {
        return a[1] < b[0] || a[0] > b[1];
    }

    std::vector<int> join(std::vector<int> a, std::vector<int> b) {
        return std::vector<int>({std::max(a[0], b[0]), std::min(a[1], b[1])});
    }
};