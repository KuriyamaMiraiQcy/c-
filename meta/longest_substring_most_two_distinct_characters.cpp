//
// Created by 62339 on 2023/11/2.
//
#include <string>
#include <unordered_map>
class longest_substring_most_two_distinct_characters {
public:
    // general to k
    int lengthOfLongestSubstringTwoDistinct(std::string s, int k = 2) {
        int start = 0;
        std::unordered_map<char, int> map;
        int result = 0;

        for (int i = 0; i < s.size(); ++i) {
            map[s[i]] = i;
            if (map.size() > k) {
                result = std::max(result, i - start);
                int index = i;
                for (auto& [k,v]:map) {
                    index = std::min(v, index);
                }
                map.erase(s[index]);
                start = index + 1;
            }
        }
        result = std::max(result, (int)s.size() - start);
        return result;
    }
};