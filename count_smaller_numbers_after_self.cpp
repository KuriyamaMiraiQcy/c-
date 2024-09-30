//
// Created by 62339 on 2023/9/4.
//
#include <vector>

class count_smaller_numbers_after_self {
    std::vector<int> result;
public:
    std::vector<int> countSmaller(std::vector<int> &nums) {
        std::vector<int> index(nums.size());
        for (int i = 0; i < index.size(); ++i) {
            index[i] = i;
        }
        result = std::vector<int>(nums.size());
        merge_sort(nums, index, 0, nums.size() - 1);
        return result;
    }

    void merge_sort(std::vector<int> &nums, std::vector<int> &index, int low, int high) {
        if (low == high) {
            return;
        }
        int mid = low + (high - low) / 2;
        merge_sort(nums, index, low, mid);
        merge_sort(nums, index, mid + 1, high);

        if (nums[index[mid]] <= nums[index[mid + 1]]) {
            return;
        }

        std::vector<int> temp(nums.size());

        int r = high, l = mid, end = high;
        while (r > mid && l >= low) {
            if (nums[index[l]] > nums[index[r]]) {
                temp[end--] = index[l];
                result[index[l--]] += r - mid;
            } else {
                temp[end--] = index[r--];
            }
        }
        while (end >= mid) {
            temp[end--] = l >= low ? index[l--] : index[r--];
        }
        for (int i = low; i <= high; ++i) {
            index[i] = temp[i];
        }
    }
};