//
// Created by 62339 on 2023/10/30.
//
#include <string>
class valid_palindrome_ii {
public:
    bool validPalindrome(std::string s, bool is_used = false) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] == s[end]) {
                ++start;
                --end;
            } else {
                if (is_used) {
                    return false;
                }
                return validPalindrome(s.substr(start, end - start), true) || validPalindrome(s.substr(start + 1, end - start), true);
            }
        }
        return true;
    }
};