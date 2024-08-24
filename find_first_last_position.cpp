//
// Created by 62339 on 2023/10/23.
//
#include <vector>
class find_first_last_position {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto find = [&](int target) -> int {
            int start = 0, end = nums.size();

            while (start < end) {
                int mid = start + (end - start) / 2;
                if (nums[mid] < target) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
            return start;
        };

        int left = find(target);
        if (left == nums.size() || nums[left] != target) {
            return std::vector<int>({-1, -1});
        }
        return std::vector<int>({left, find(target + 1) - 1});
    }

};