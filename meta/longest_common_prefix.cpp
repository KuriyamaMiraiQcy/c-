//
// Created by 62339 on 2023/10/29.
//
#include <vector>
#include <string>
class longest_common_prefix {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        for (int i = 0; i < strs[0].size(); ++i) {
            char pivot = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (pivot == strs[j].size() || strs[j][i] != pivot) {
                    return strs[j].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};