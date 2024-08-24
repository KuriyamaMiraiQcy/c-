//
// Created by 62339 on 2023/8/29.
//
#include <vector>
#include <cmath>
#include <iostream>

class min_subarray {
public:
    int minSubArray(std::vector<int> &nums) {
        int sum = 0, result = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum <= 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            result = std::min(result, sum);
        }
        return result;
    }

    int min_subArray_not_less_k(std::vector<int> nums, int k) {

        int sum = 0, max_prefix = INT_MIN, prefix_sum = 0, result = INT_MAX;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i];
            prefix_sum += nums[i - k];
            max_prefix = std::max(max_prefix, prefix_sum);
            result = std::min(result, sum - max_prefix);
        }
        return result;
    }

    int min_subArray_not_great_k(std::vector<int> nums, int k) {

        int sum = 0, result = INT_MAX;
        std::vector<int> suffix_k(k, 0);
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
            result = std::min(result, sum);
            suffix_k[i] = sum;
        }
        sum = 0;
        for (int i = 0; i < nums.size() - k; ++i) {
            sum += nums[i];
            int min_suffix = INT_MAX;
            for (int j = 1; j <= k; ++j) {
                suffix_k[j - 1] += nums[i + j];
                min_suffix = std::min(suffix_k[j - 1], min_suffix);
            }
            result = std::min(result, min_suffix - sum);
        }
        return result;
    }
};

//int main() {
//    min_subarray a;
//    std::cout << a.min_subArray_not_great_k(std::vector<int>({1, 12, -5, -6, 50, 3}), 3);
//}