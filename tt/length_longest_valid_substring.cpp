//
// Created by 62339 on 2023/11/23.
//
#include <string>
#include <vector>
#include <unordered_set>
class length_longest_valid_substring {
public:
    int longestValidSubstring(std::string word, std::vector<std::string>& forbidden) {
        std::unordered_set<std::string> banned(forbidden.begin(), forbidden.end());
        int start = 0, result = 0;

        for (int end = 0; end < word.size(); ++end) {
            for (int i = end; i >= start && i > end - 10 ; --i) {
                if (banned.find(word.substr(i, end - i + 1)) != banned.end()) {
                    start = i + 1;
                    break;
                }
            }
            result = std::max(result, end - start + 1);
        }
        return result;
    }
};