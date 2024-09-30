//
// Created by 62339 on 2023/10/29.
//
#include <string>
#include <stack>
#include <iostream>

class delete_string {
public:
    std::string delete_3_characters(std::string& s) {
        std::stack<std::pair<char, int>> stack;

        auto pop = [&](char ch){
            while (!stack.empty() && stack.top().first != ch && stack.top().second >= 3) {
                stack.pop();
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            if (stack.empty()) {
                stack.emplace(s[i], 1);
                continue;
            }
            if (stack.top().first == s[i]) {
                stack.top().second++;
            } else {
                pop(s[i]);
                if (stack.empty() || stack.top().first != s[i]) {
                    stack.emplace(s[i], 1);
                } else {
                    stack.top().second++;
                }
            }
        }

        pop('\0');

        std::string result;
        while (!stack.empty()) {
            std::string compose;
            for (int i = 0; i < stack.top().second; ++i) {
                compose += stack.top().first;
            }
            result = compose + result;
            stack.pop();
        }

        return result;
    }
};

//int main() {
//    std::string str = "aabbbaccddddc";
//    std::string str1 = "aabbbaccddfddccc";
//    delete_string a;
//    std::cout << a.delete_3_characters(str) << std::endl;
//    std::cout << a.delete_3_characters(str1) << std::endl;
//}