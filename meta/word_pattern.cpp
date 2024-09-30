//
// Created by 62339 on 2023/11/2.
//
#include <string>
#include <unordered_map>
class word_pattern {
public:
    bool wordPattern(std::string pattern, std::string s) {
        s += " ";

        int index = -1;
        std::unordered_map<char, std::string> map;
        std::unordered_map<std::string, char> reverse;
        for (int i = 0; i < pattern.size(); ++i) {
            ++index;
            std::string word;
            while (index < s.size() && s[index] != ' ') {
                word += s[index++];
            }
            if ((map.find(pattern[i]) != map.end() && map[pattern[i]] != word) || (reverse.find(word) != reverse.end() && reverse[word] != pattern[i])) {
                return false;
            }
            map[pattern[i]] = word;
            reverse[word] = pattern[i];
        }
        return index == s.size() - 1;
    }
};