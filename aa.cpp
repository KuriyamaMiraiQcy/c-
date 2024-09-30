#include <string>
#include <unordered_map>
#include <iostream>

//
// Created by 62339 on 2024/1/18.
//
class calculate_unique {
public:
    std::string get_unique_substring(std::string& s) {
        std::unordered_map<char, int> loc;

        int start = 0, len = 0, res_start = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (loc.find(s[i]) == loc.end()) {
                loc[s[i]] = i;
                continue;
            }
            if (i - start > len) {
                len = i - start;
                res_start = start;
            }
            start = std::max(loc[s[i]] + 1, start);
            loc[s[i]] = i;
//            std::cout << "start:" <<start;
        }

        if (s.size() - start > len) {
            len = s.size() - start;
            res_start = start;
        }

        return s.substr(res_start, len);
    }
};

//H:\av\abp