//
// Created by 62339 on 2023/10/27.
//
#include <vector>
class merge_sorted_array {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i) {
            nums1.emplace_back(0);
        }

        for (int i = m - 1; i >= 0; --i) {
            std::swap(nums1[i], nums1[i + n]);
        }

        int i1 = n, i2 = 0, fill = 0;
        while (i1 < m + n && i2 < n) {
            if (nums1[i1] <= nums2[i2]) {
                nums1[fill++] = nums1[i1++];
            } else {
                nums1[fill++] = nums2[i2++];
            }
        }

        while (i2 != n) {
            nums1[fill++] = nums2[i2++];
        }
    }
};