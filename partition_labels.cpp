//
// Created by 62339 on 2023/10/22.
//
#include <vector>
#include <string>
#include <unordered_map>
class partition_labels {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::unordered_map<int, int> loc;

        for (int i = 0; i < s.size(); ++i) {
            loc[s[i] - 'a'] = std::max(loc[s[i] - 'a'], i);
        }

        int start = 0, end = 0;
        std::vector<int> result;

        for (int i = 0; i < s.size(); ++i) {
            end = std::max(end, loc[s[i] - 'a']);
            if (end == i) {
                result.emplace_back(end - start + 1);
                start = end + 1;
                end = end + 1;
            }
        }
        return result;
    }
};