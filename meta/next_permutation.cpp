//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class next_permutation {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i;
        for (i = nums.size()-2;i>=0;--i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        auto reverse= [&](int i, int j) {
            while (i < j) {
                std::swap(nums[i++], nums[j--]);
            }
        };
        if (i == -1) {
            reverse(0, nums.size() - 1);
            return;
        }
        int j;
        for (j = nums.size() - 2; j > i; j--) {
            if (nums[j] > nums[i] && nums[j + 1] <= nums[i]) {
                break;
            }
        }
        if (j == i) {
            j = nums.size() - 1;
        }
        std::swap(nums[i], nums[j]);
        reverse(i + 1, nums.size() - 1);
    }
};