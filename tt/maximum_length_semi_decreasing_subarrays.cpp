//
// Created by 62339 on 2023/11/28.
//
#include <vector>
#include <numeric>
#include <algorithm>

class maximum_length_semi_decreasing_subarrays {
public:
    int maxSubarrayLength(std::vector<int>& nums) {
        std::vector<int> ids;
        int result = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (ids.empty() || nums[i] > nums[ids.back()]) {
                ids.emplace_back(i);
            } else {
                int start = 0, end = ids.size();
                while (start < end) {
                    int mid = start + (end - start) / 2;
                    if (nums[ids[mid]] <= nums[i]) {
                        start = mid + 1;
                    } else {
                        end = mid;
                    }
                }
                if (start == ids.size()) {
                    continue;
                }
                result = std::max(result, i - ids[start] + 1);
            }
        }
        return result;
    }
};