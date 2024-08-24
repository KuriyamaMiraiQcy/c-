//
// Created by 62339 on 2023/8/26.
//
#include <vector>
#include <string>

class summary_ranges {
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums) {
        std::vector<std::string> result;
        if (nums.size() == 0) {
            return result;
        }
        int left = nums[0], right = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                result.emplace_back(nums[i - 1] == left ? std::to_string(left) : std::to_string(left) + "->" +
                                                                                 std::to_string(right));
                left = nums[i];
            }
        }
        result.emplace_back(nums[nums.size() - 1] == left ? std::to_string(left) : std::to_string(left) + "->" +
                                                                                   std::to_string(right));
        return result;
    }
};
