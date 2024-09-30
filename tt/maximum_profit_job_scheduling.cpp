//
// Created by 62339 on 2023/11/26.
//
#include <vector>
#include <numeric>
#include <algorithm>

class maximum_profit_job_scheduling {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        std::vector<std::vector<int>> ids(startTime.size());
        for (int i = 0; i < startTime.size(); ++i) {
            ids[i] = {startTime[i], endTime[i], profit[i]};
        }

        std::stable_sort(ids.begin(), ids.end(), [](auto& i, auto& j) -> bool {
           return i[1] < j[1];
        });

        std::vector<int> dp(startTime.size() + 1);
        dp[0] = 0;

        for (int i = 1; i < dp.size(); ++i) {
            int start = 0, end = i - 1;
            int target = ids[i - 1][0] + 1;

            while (start < end) {
                int mid = start + (end - start) / 2;
                if (ids[mid][1] < target) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
            dp[i] = std::max(dp[i - 1], dp[start] + ids[i - 1][2]);
        }
        return dp[startTime.size()];
    }
};