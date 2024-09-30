//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class maximum_sum_3_non_overlapping_subarrays {
public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
        int sum1 = 0, max_sum1 = 0,index1 = 0;
        int sum2 = 0, max_sum12 = 0;
        int sum3 = 0, total = 0;
        std::pair<int, int> index12;
        std::vector<int> result;

        for (int i = 0; i + 2 * k < nums.size();++i) {
            sum1 += nums[i];
            sum2 += nums[i + k];
            sum3 += nums[i + 2 * k];
            if (i < k - 1) {
                continue;
            }
            if (sum1 > max_sum1) {
                max_sum1 = sum1;
                index1 = i - k + 1;
            }
            if (max_sum1 + sum2 > max_sum12) {
                max_sum12 = max_sum1 + sum2;
                index12 = {index1, i + 1};
            }
            if (max_sum12 + sum3 > total) {
                total = max_sum12 + sum3;
                result = std::vector<int>({index12.first, index12.second, i+k + 1});
            }
            sum1 -= nums[i - k + 1];
            sum2 -= nums[i + 1];
            sum3 -= nums[i + k + 1];
        }
        return result;
    }
};