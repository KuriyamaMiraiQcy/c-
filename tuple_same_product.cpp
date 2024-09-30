//
// Created by 62339 on 2023/10/19.
//
#include <vector>
#include <unordered_map>

class tuple_same_product {
public:
    int tupleSameProduct(std::vector<int> &nums) {
        std::unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                count[nums[i] * nums[j]]++;
            }
        }

        int result = 0;
        for (auto &[n, v]: count) {
            result += v * (v - 1) * 4;
        }
        return result;
    }
};