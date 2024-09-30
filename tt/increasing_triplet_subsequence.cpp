//
// Created by 62339 on 2023/11/23.
//
#include <vector>
#include <climits>

class increasing_triplet_subsequence {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int first = nums[0], second = INT_MAX;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > second) {
                return true;
            }
            if (nums[i] <= first) {
                first = nums[i];
            } else {
                second = nums[i];
            }
        }
        return false;
    }
};