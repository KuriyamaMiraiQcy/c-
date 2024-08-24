//
// Created by 62339 on 2023/8/19.
//
#include <vector>
#include <algorithm>

class power_of_heroes {
public:
    int sumOfPower(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> prefix_sum(nums.size());
        int sum = 0;
        for (int i = 0; i < prefix_sum.size(); ++i) {
            sum += nums[i];
            prefix_sum[i] = sum;
        }

        sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = sum * nums[i] + prefix_sum[i];
        }
        return sum;
    }
};
