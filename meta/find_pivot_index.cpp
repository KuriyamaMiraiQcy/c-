//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class find_pivot_index {
public:
    int pivotIndex(std::vector<int>& nums) {
        std::vector<int> prefix_sum(nums.size(), 0);

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i] = sum;
            sum += nums[i];
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (sum - nums[i] == prefix_sum[i] * 2) {
                return i;
            }
        }
        return -1;
    }
};