//
// Created by 62339 on 2023/9/23.
//
#include <vector>
#include <cmath>
#include <stack>

class largest_rectangle_histogram {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        int result = 0;
        std::stack<int> increasing;
        std::vector<int> left(heights.size()), right(heights.size());

        for (int i = 0; i < heights.size(); ++i) {
            while (!increasing.empty() && heights[increasing.top()] >= heights[i]) {
                increasing.pop();
            }
            left[i] = increasing.empty() ? -1 : increasing.top();
            increasing.push(i);
        }

        increasing = std::stack<int>();
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!increasing.empty() && heights[increasing.top()] >= heights[i]) {
                increasing.pop();
            }
            right[i] = increasing.empty() ? heights.size() : increasing.top();
            increasing.push(i);
        }

        for (int i = 0; i < heights.size(); ++i) {
            result = std::max(result, (right[i] - left[i] - 1) * heights[i]);
        }
        return result;
    }
};