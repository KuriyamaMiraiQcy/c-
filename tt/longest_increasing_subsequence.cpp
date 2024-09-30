//
// Created by 62339 on 2023/11/23.
//
#include <vector>
class longest_increasing_subsequence {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> increasing;
        increasing.emplace_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            int index = std::lower_bound(increasing.begin(), increasing.end(), nums[i]) - increasing.begin();
            if (index == increasing.size()) {
                increasing.emplace_back(nums[i]);
            } else {
                increasing[index] = nums[i];
            }
        }
        return increasing.size();
    }
};