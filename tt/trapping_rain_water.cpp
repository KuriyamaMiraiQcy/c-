//
// Created by 62339 on 2023/11/26.
//
#include <vector>
class trapping_rain_water {
public:
    int trap(std::vector<int>& height) {
        int max = height[0];
        std::vector<int> fill_height(height.size(), 0);

        for (int i = 1; i < height.size(); ++i) {
            fill_height[i] = max;
            max = std::max(max, height[i]);
        }

        max = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            fill_height[i] = std::min(fill_height[i], max);
            max = std::max(max, height[i]);
        }

        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            result += fill_height[i] - height[i];
        }
        return result;
    }
};