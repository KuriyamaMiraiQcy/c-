//
// Created by 62339 on 2023/10/18.
//
#include <vector>
#include <queue>

class maximal_score_after_k_operations {
public:
    long long maxKelements(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<>> pq(nums.begin(), nums.end());

        long long result = 0;
        while (k > 0) {
            result += pq.top();
            int next = (pq.top() + 2) / 3;
            pq.pop();
            pq.push(next);
            --k;
        }

        return result;
    }
};