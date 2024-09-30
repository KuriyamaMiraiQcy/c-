//
// Created by 62339 on 2023/11/29.
//
#include <vector>
#include <unordered_map>
class pairs_songs_total_durations_divisible {
public:
    int numPairsDivisibleBy60(std::vector<int>& time) {
        std::unordered_map<int, int> count;

        int result = 0;
        for (auto& t:time) {
            if (count.find((60 - t % 60) % 60) != count.end()) {
                result += count[(60 - t % 60) % 60];
            }
            count[t % 60]++;
        }
        return result;
    }
};