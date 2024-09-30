//
// Created by 62339 on 2023/11/1.
//
#include <string>
#include <iostream>

class parse_nested_integer {
public:
    int parse(std::string s) {
        int num = 0, level = 0, result = 0;
        for (auto& ch:s) {
            switch(ch) {
                case '[':
                    ++level;
                    break;
                case ']':
                    result += num * level;
                    num = 0;
                    --level;
                    break;
                case ',':
                    result += num * level;
                    num = 0;
                    break;
                default:
                    num = num * 10 + (ch - '0');
                    break;
            }
        }
        return result;
    }
};

//int main() {
//    parse_nested_integer a;
//    std::cout << a.parse("[4,[5,6]]");
//    std::cout << a.parse("[8,4,[5,[9],3],6]");
//}