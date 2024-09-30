//
// Created by 62339 on 2023/11/27.
//
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

class split_array_largest_sum {
public:
    int splitArray(std::vector<int>& nums, int n) {
        std::vector<std::vector<long long>> dp(nums.size() + 1, std::vector<long long>(n + 1, LLONG_MAX));
        std::vector<long long> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        dp[0][0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= std::min(i, n); ++j) {
                for (int k = 0; k < i; ++k) {
                    dp[i][j] = std::min(dp[i][j], std::max(dp[k][j - 1],prefix[i] - prefix[k]));
                }
            }
        }
        return dp[nums.size()][n];
    }

    int split_array(std::vector<int>& nums, int n) {
        int end = std::accumulate(nums.begin(), nums.end(), 0);
        int start = *std::max_element(nums.begin(), nums.end());

        auto is_valid = [&](int num) ->bool {
            int sum = 0, count = 1;
            for (auto& i:nums) {
                if (i + sum > num) {
                    ++count;
                    sum = i;
                } else {
                    sum += i;
                }
            }
            return count <= n;
        };

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (!is_valid(mid)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};