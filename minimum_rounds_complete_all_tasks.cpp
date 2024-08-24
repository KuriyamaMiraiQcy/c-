//
// Created by 62339 on 2024/5/14.
//
#include <vector>
#include <unordered_map>
class minimum_rounds_complete_all_tasks {
public:
    int minimumRounds(std::vector<int>& tasks) {
        std::unordered_map<int, int> count;
        for (auto& t:tasks) {
            count[t]++;
        }

        int result = 0;
        for (auto& [k,v]: count) {
            if (v == 1) {
                return -1;
            }
            if (v % 3 == 0) {
                result += v / 3;
            } else {
                result += v / 3 + 1;
            }
        }
        return result;
    }
};