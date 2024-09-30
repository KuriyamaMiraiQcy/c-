//
// Created by 62339 on 2023/10/19.
//
#include <vector>

class intersection_three_sorted_arrays {
public:
    std::vector<int> arraysIntersection(std::vector<int> &arr1, std::vector<int> &arr2, std::vector<int> &arr3) {
        int target = std::max(arr1[0], std::max(arr2[0], arr3[0]));

        int p1 = 0, p2 = 0, p3 = 0;

        std::vector<int> result;
        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) {
            if (arr1[p1] < target) {
                p1++;
                target = std::max(target, arr1[p1]);
                continue;
            }
            if (arr2[p2] < target) {
                p2++;
                target = std::max(target, arr2[p2]);
                continue;
            }
            if (arr3[p3] < target) {
                p3++;
                target = std::max(target, arr3[p3]);
                continue;
            }
            result.emplace_back(target);
            p1++;
            p2++;
            p3++;
            target = std::max(arr1[p1], std::max(arr2[p2], arr3[p3]));
        }

        return result;
    }
};