//
// Created by 62339 on 2023/10/28.
//
#include <string>
class minimum_add_parentheses_valid {
public:
    int minAddToMakeValid(std::string s) {
        int open = 0;
        int result = 0;
        for (auto& ch:s) {
            if (ch =='(') {
                ++open;
            }
            if (ch == ')') {
                if (open > 0) {
                    --open;
                } else {
                    result++;
                }
            }
        }
        return result + open;
    }
};