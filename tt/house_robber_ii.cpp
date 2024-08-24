//
// Created by 62339 on 2023/11/18.
//
#include <vector>
class house_robber_ii {
public:
    int rob(std::vector<int>& nums) {
        int result = 0;
        auto rob_range = [&](int start, int last) {
            int prev = 0, cur = nums[start];

            for (int i = start + 1; i < last; ++i) {
                int temp = cur;
                cur = std::max(cur, prev + nums[i]);
                prev = temp;
            }
            result = std::max(result, cur);
        };

        if (nums.size() == 1) {
            return nums[0];
        }
        rob_range(0, nums.size() -1);
        rob_range(1, nums.size());
        return result;
    }
};