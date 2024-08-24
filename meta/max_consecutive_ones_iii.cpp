//
// Created by 62339 on 2023/10/28.
//
#include <vector>

class max_consecutive_ones_iii {
public:
    int longestOnes(std::vector<int> &nums, int k) {
        int left = 0, count = 0, result = 0;

        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                if (count < k) {
                    count++;
                } else {
                    result = std::max(result, r - left);
                    if (nums[left] == 1) {
                        while (nums[left] == 1) left++;
                    }
                    ++left;
                }
            }
        }
        result = std::max(result, (int) nums.size() - left);
        return result;
    }
};