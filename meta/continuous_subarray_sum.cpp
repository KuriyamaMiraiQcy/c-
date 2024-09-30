//
// Created by 62339 on 2023/11/7.
//
#include <vector>
#include <unordered_map>
class continuous_subarray_sum {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int sum = 0;
        std::unordered_map<int, int> index;
        index[0] = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (index.find(sum % k) != index.end() && i - index[sum%k] >= 2) {
                return true;
            }
            if (index.find(sum % k) == index.end()) {
                index[sum%k] = i;
            }
        }
        return false;
    }
};