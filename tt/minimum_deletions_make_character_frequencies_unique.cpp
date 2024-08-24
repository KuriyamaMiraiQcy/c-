//
// Created by 62339 on 2023/11/28.
//
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>

class minimum_deletions_make_character_frequencies_unique {
public:
    int minDeletions(std::string s) {
        std::vector<int> count(26, 0);

        for (auto& ch:s) {
            count[ch - 'a']++;
        }
        std::unordered_set<int> set;
        for (auto& c:count) {
            while (c > 0 && set.find(c) != set.end()) {
                --c;
            }
            set.emplace(c);
        }

        return s.size() - std::accumulate(set.begin(), set.end(), 0);

    }
};