//
// Created by 62339 on 2023/8/24.
//
#include <string>
#include <vector>
#include <unordered_map>

class minimum_window_substring {
public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> t_set(256, 0);
        std::vector<int> s_set(256, 0);
        for (char ch:t) {
            ++t_set[ch];
        }

        int start = 0, end = 0, length = INT_MAX;
        int res_start = -1;
        while (end < s.size()) {
            ++s_set[s[end++]];
            while (is_equal(s_set, t_set) && start <= end) {
                if (length > end - start) {
                    length = end - start;
                    res_start = start;
                }
                --s_set[s[start++]];
            }
        }
        return length == INT_MAX? "" : s.substr(res_start, length);
    }

    static bool is_equal(std::vector<int>& a, std::vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < b[i]){
                return false;
            }
        }
        return true;
    }
};
