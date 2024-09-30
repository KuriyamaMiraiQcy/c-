//
// Created by 62339 on 2024/5/14.
//
#include <vector>
#include <string>
#include <unordered_map>
class substring_concatenation_all_words {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        int count = words.size(), length = words[0].size();
        std::vector<int> result;
        for (int i = 0; i + count * length <= s.size() && i < length; ++i) {
            std::unordered_map<std::string, int> w;
            for (int j = 0; j < count; ++j) {
                w[s.substr(i + j * length, length)]++;
            }

            for (auto& word:words) {
                if (--w[word] == 0) {
                    w.erase(word);
                }
            }

            if (w.empty()) {
                result.emplace_back(i);
            }

            for (int j = i; j + count * length <= s.size(); j += length) {
                std::string word = s.substr(j, length);
                if (--w[word] == 0) {
                    w.erase(word);
                }
                word = s.substr(j + count * length, length);
                if (++w[word] == 0) {
                    w.erase(word);
                }
                if (w.empty()) {
                    result.emplace_back(j + length);
                }
            }
        }
        return result;
    }
};