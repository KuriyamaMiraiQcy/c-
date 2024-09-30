//
// Created by 62339 on 2023/9/23.
//
#include <vector>
#include <unordered_map>

class top_k_frequent_elements {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> count;

        for (int n: nums) {
            if (count.find(n) == count.end()) {
                count[n] = 0;
            }
            count[n] = count[n] + 1;
        }

        std::vector<std::vector<int>> bucket(nums.size() + 1, std::vector<int>());
        for (auto start = count.begin(); start != count.end(); start++) {
            bucket[start->second].emplace_back(start->first);
        }

        std::vector<int> result;

        for (int i = nums.size(); i >= 0; --i) {
            if (result.size() == k) {
                break;
            }
            if (!bucket[i].empty()) {
                for (int n: bucket[i]) result.emplace_back(n);
            }
        }
        return result;
    }
};