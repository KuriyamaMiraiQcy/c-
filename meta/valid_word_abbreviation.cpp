//
// Created by 62339 on 2023/10/19.
//
#include <string>
class valid_word_abbreviation {
public:
    bool validWordAbbreviation(std::string word, std::string abbr) {
        int index = 0, num = 0;

        for (int i = 0; i < abbr.size(); ++i) {
            if (abbr[i] >= '0' && abbr[i] <= '9') {
                num = num * 10 + (abbr[i] - '0');
                if (num > 20 || num == 0) {
                    return false;
                }
            } else {
                if (num != 0) {
                    index += num;
                    num = 0;
                }
                if (abbr[i] != word[index]) {
                    return false;
                }
                index++;
            }
        }
        return index + num == word.size();
    }
};