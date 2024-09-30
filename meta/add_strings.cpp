//
// Created by 62339 on 2023/11/1.
//
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

class add_strings {
public:
    std::string addStrings(std::string& num1, std::string& num2) {
        auto find_dot = [&](std::string& s) -> int {
            int index = 0;
            for (;index < s.size(); ++index) {
                if (s[index] == '.'){
                    break;
                }
            }
            return index;
        };

        int dot_1 = find_dot(num1);
        int dot_2 = find_dot(num2);

        auto add = [](std::string& s1, std::string& s2, int advance = 0) -> std::string {
            std::string result;
            for (int i = s1.size() - 1; i >= 0; --i) {
                int res= s1[i] - '0'
                        + s2[i] - '0' + advance;
                advance = res/ 10;
                result += (char)('0' + res % 10);
            }
            if (advance == 1) {
                result += '1';
            }
            std::reverse(result.begin(), result.end());
            return result;
        };

        auto add_zero = [](std::string& s1, std::string& s2, bool is_left) {
            int num = abs((int)s1.size() - (int)s2.size());
            if (num == 0) {
                return;
            }
            std::string zeroes = "";
            for (int i = 0; i < num; ++i) {
                zeroes += '0';
            }
            if (is_left) {
                if (s1.size() < s2.size()) {
                    s1 = zeroes + s1;
                } else {
                    s2 = zeroes + s2;
                }
                return;
            }
            if (s1.size() < s2.size()) {
                s1 += zeroes;
            } else {
                s2 += zeroes;
            }
        };

        std::string l1 = num1.substr(0, dot_1);
        std::string l2 = num2.substr(0, dot_2);
        add_zero(l1, l2, true);
        if (dot_1 == num1.size() && dot_2 == num2.size()) {
            return add(l1, l2);
        }

        std::string r1 = num1.substr(dot_1 + 1, num1.size() - dot_1 - 1);
        std::string r2 = num2.substr(dot_2 + 1, num2.size() - dot_2 - 1);
        add_zero(r1, r2, false);

        std::string r = add(r1, r2);
        int adv = 0;
        if (r.size() > r1.size()) {
            r = r.substr(1, r.size() - 1);
            adv = 1;
        }
        return add(l1, l2, adv) + "." + r;
    }
};

//int main() {
//    add_strings a;
//    std::string s1 = "3.75";
//    std::string s2 = "15.375";
//    std::cout << a.addStrings(s1, s2);
//}
