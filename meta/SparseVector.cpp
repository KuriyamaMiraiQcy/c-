//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class SparseVector {
public:

    SparseVector(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            storage.emplace_back(i, nums[i]);
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int s1 = 0, s2 = 0;
        int result = 0;
        while (s1 != storage.size() && s2 != vec.storage.size()) {
            if (storage[s1].first == vec.storage[s2].first) {
                result += storage[s1].second * vec.storage[s2].second;
                s1++;
                s2++;
                continue;
            }
            if (storage[s1].first < vec.storage[s2].first) {
                s1++;
            } else {
                s2++;
            }
        }
        return result;
    }

private:
    std::vector<std::pair<int, int>> storage;
};