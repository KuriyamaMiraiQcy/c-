//
// Created by 62339 on 2023/10/31.
//
#include <vector>
class remove_duplicates_sorted_array {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int count = 1, index = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                std::swap(nums[index++], nums[i]);
                ++count;
            }
        }
        std::swap(nums[index], nums[nums.size() - 1]);
        return count;
    }
};