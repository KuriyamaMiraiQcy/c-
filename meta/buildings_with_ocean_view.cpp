//
// Created by 62339 on 2023/10/30.
//
#include <vector>
class buildings_with_ocean_view {
public:
    std::vector<int> findBuildings(std::vector<int>& heights) {
        std::vector<int> result;
        result.emplace_back(heights.size() - 1);

        int highest = heights[heights.size() - 1];

        for (int i = heights.size() - 2; i >= 0; --i) {
            if (heights[i] > highest) {
                highest = heights[i];
                result.emplace_back(i);
            }
        }

        for (int i = 0; i < result.size() / 2; ++i) {
            std::swap(result[i], result[result.size() - 1 - i]);
        }
        return result;
    }
};