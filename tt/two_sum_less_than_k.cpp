#include <vector>
#include <algorithm>

//
// Created by 62339 on 2023/11/26.
//
class two_sum_less_than_k {
public:
    int twoSumLessThanK(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int result = INT_MIN;
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] < k) {
                result = std::max(result, nums[start++] + nums[end]);
            } else {
                --end;
            }
        }
        return result == INT_MIN ? -1 : result;
    }
};