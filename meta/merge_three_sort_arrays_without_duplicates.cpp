//
// Created by 62339 on 2023/10/31.
//
#include <vector>
#include <climits>
#include <iostream>

class merge_three_sort_arrays_without_duplicates {
public:
    std::vector<int> merge_arrays(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
        int target = std::min(arr1[0], std::min(arr2[0], arr3[0]));

        std::vector<int> result;
        int p1 = 0, p2 = 0, p3 = 0;
        while (p1<arr1.size() || p2 < arr2.size() || p3 < arr3.size()) {
            if (p1<arr1.size() && arr1[p1] == target) {
                ++p1;
                continue;
            }
            if (p2 < arr2.size() && arr2[p2] == target) {
                ++p2;
                continue;
            }
            if (p3 < arr3.size() && arr3[p3] == target) {
                ++p3;
                continue;
            }
            result.emplace_back(target);
            target = std::min(p1 < arr1.size()?arr1[p1]:INT_MAX, std::min(p2 < arr2.size()?arr2[p2]:INT_MAX, p3 < arr3.size()?arr3[p3]:INT_MAX));
        }
        result.emplace_back(target);
        return result;
    }
};

//int main() {
//    std::vector<int> a1({1, 1, 2, 2});
//    std::vector<int> a2({1, 2, 4});
//    std::vector<int> a3({2, 2, 3, 3, 4, 4, 5, 5});
//    std::vector<int> a4({1, 2, 3, 4, 5});
//
//    merge_three_sort_arrays_without_duplicates a;
//    for (int& n:a.merge_arrays(a1, a2, a3)) {
//        std::cout << n;
//    }
//}