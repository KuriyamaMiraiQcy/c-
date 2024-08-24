//
// Created by 62339 on 2023/10/19.
//
#include <vector>
#include <unordered_map>
class subarray_sum_equals_k {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        count[0] = 1;

        int sum = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (count.find(sum - k) != count.end()) {
                result += count[sum - k];
            }
            count[sum]++;
        }
        return result;
    }
};