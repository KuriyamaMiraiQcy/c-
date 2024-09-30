//
// Created by 62339 on 2023/11/17.
//
#include <string>
class backspace_string_compare {
public:
    void rebuild(std::string &s) {
        int l = 0;
        for (char c: s) {
            if (c == '#') {
                if (l > 0) l--;
            } else {
                s[l++] = c;
            }
        }
        s.resize(l);
    }

    bool backspaceCompare(std::string s, std::string t) {
        rebuild(s);
        rebuild(t);
        return s==t;
    }
};