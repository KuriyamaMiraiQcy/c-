//
// Created by 62339 on 2023/10/14.
//
#include <string>
#include <vector>

class letter_combinations {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.size() == 0) {
            return result;
        }
        result.emplace_back("");

        for (int i = 0; i < digits.size(); ++i) {
            int num = digits[i] - '2';
            std::vector<std::string> temp;
            for (const std::string &s: result) {
                for (char j: index[num]) {
                    temp.emplace_back(s + j);
                }
            }
            result = temp;
        }
        return result;
    }

private:
    const std::string index[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};