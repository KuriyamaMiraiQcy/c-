//
// Created by 62339 on 2023/10/17.
//
#include <string>

class valid_number {
public:
    bool isNumber(std::string s) {
        int e_index = 0;
        while (e_index < s.size()) {
            if (s[e_index] == 'e' || s[e_index] == 'E') {
                break;
            }
            ++e_index;
        }
        if (e_index < s.size()) {
            return (is_decimal(s.substr(0, e_index)) || is_integer(s.substr(0, e_index))) &&
                   is_integer(s.substr(e_index + 1, s.size() - e_index - 1));
        }
        return is_decimal(s) || is_integer(s);
    }

    bool is_decimal(std::string s) {
        if (s.size() <= 1) {
            return false;
        }
        if (s[0] == '+' || s[0] == '-') {
            return is_decimal(s.substr(1, s.size() - 1));
        }
        int dot = 0;
        while (dot < s.size()) {
            if (s[dot] == '.') {
                break;
            }
            ++dot;
        }
        if (dot == s.size()) {
            return false;
        }

        for (int i = 0; i < dot; ++i) {
            if (i == 0 && (s[i] == '+' || s[i] == '-')) {
                continue;
            }
            if (is_digit(s[i])) {
                continue;
            }
            return false;
        }

        for (int i = dot + 1; i < s.size(); ++i) {
            if (!is_digit(s[i])) {
                return false;
            }
        }
        return true;
    }

    bool is_integer(std::string s) {
        if (s.size() == 0) {
            return false;
        }
        if (s[0] == '+' || s[0] == '-') {
            return is_integer(s.substr(1, s.size() - 1));
        }
        int index = 0;
        while (index < s.size()) {
            if (!is_digit(s[index])) {
                return false;
            }
            ++index;
        }

        return true;
    }

    bool is_digit(char ch) {
        return ch >= '0' && ch <= '9';
    }
};