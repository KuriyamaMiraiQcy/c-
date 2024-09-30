//
// Created by 62339 on 2023/11/27.
//
#include <vector>
class missing_ranges {
    std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
        std::vector<std::vector<int>> result;

        for (int num:nums) {
            if (num < lower || lower > upper) {
                continue;
            }
            if (num == lower) {
                lower++;
                continue;
            }
            result.emplace_back(std::vector<int>({lower, num - 1}));
            lower = num + 1;
        }
        if (lower <= upper) {
            result.emplace_back(std::vector<int>({lower, upper}));
        }
        return result;
    }
};