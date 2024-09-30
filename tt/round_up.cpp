//
// Created by 62339 on 2023/11/26.
//
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iostream>

class round_up {
public:
    std::vector<int> round(std::vector<double>& nums) {
        double sum = 0.0;
        int round_sum = 0;

        for (auto& n:nums) {
            sum += n;
            round_sum += floor(n);
        }

        int k = (int)floor(sum) - round_sum;

        std::vector<int> ids(nums.size());
        std::iota(ids.begin(), ids.end(), 0);

        std::stable_sort(ids.begin(), ids.end(), [&](int i, int j) -> bool {
            return nums[i] - floor(nums[i]) < nums[j] - floor(nums[j]);
        });

        std::vector<int> result(nums.size());
        for (int i = 0; i < k; ++i) {
            int index = ids[nums.size() - 1 - i];
            result[index] = (int)floor(nums[index]) + 1;
        }

        for (int i = 0; i < nums.size() - k; ++i) {
            int index = ids[i];
            result[index] = (int)floor(nums[index]);
        }
        return result;
    }
};

//int main() {
//    round_up a;
//    std::vector<double> t({2.1, 0.3, 6.6, 9.1, 10.0});
//    for (auto& i:a.round(t)) {
//        std::cout << i << std::endl;
//    }
//}