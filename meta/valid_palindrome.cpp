//
// Created by 62339 on 2023/10/29.
//
#include <string>
class valid_palindrome {
public:
    bool isPalindrome(std::string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (!isalnum(s[start])) {
                ++start;
                continue;
            }
            if (!isalnum(s[end])) {
                --end;
                continue;
            }
            if (std::tolower(s[start++]) != std::tolower(s[end--])) {
                return false;
            }
        }
        return true;
    }
};