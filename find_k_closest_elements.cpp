//
// Created by 62339 on 2023/10/25.
//
#include <vector>
#include <algorithm>
class find_k_closest_elements {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int index = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = index, right = index + 1, count = 0;
        std::vector<int> result;
        while (count < k) {
            if (!std::abs(arr[right] - x) < std::abs(arr[left] - x)) {
                result.emplace_back(arr[left--]);
            } else {
                result.emplace_back(arr[right++]);
            }
            ++count;
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};