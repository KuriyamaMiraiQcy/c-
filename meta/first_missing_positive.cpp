//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class first_missing_positive {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};