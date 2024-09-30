//
// Created by 62339 on 2023/11/23.
//
#include <string>
#include <unordered_map>
class valid_anagram {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> map;

        for (auto& ch:s) {
            map[ch]++;
        }

        for (auto& ch:t) {
            if (map.find(ch) == map.end() || map[ch] ==0) {
                return false;
            }
            map[ch]--;
        }

        int sum = 0;
        for (auto& [k, v]:map) {
            sum += v;
        }
        return sum == 0;
    }
};