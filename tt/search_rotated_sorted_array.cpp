//
// Created by 62339 on 2023/11/24.
//
#include <vector>
class search_rotated_sorted_array {
public:
    int search(std::vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[nums.size() - 1]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};