//
// Created by 62339 on 2023/8/21.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class version {
public:
    int output_version() {
        std::string version_1, version_2;
        std::cin >> version_1;
        std::cin >> version_2;

        std::vector<int> sub_1, sub_2;
        handle_version(&version_1, &sub_1);
        handle_version(&version_2, &sub_2);

        for (int i = 0; i < std::max(sub_1.size(), sub_2.size()); ++i) {
            int s_1 = i < sub_1.size() ? sub_1[i] : 0;
            int s_2 = i < sub_2.size() ? sub_2[i] : 0;
            if (s_1 != s_2) {
                return s_1 < s_2 ? -1 : 1;
            }
        }
        return 0;
    }

    void handle_version(std::string *s, std::vector<int> *subs) {
        char delimiter = '.';
        auto start = 0, end = 0;
        while (start < s->size()) {
            end = s->find(delimiter, start);
            if (end == std::string::npos) {
                end = s->size();
            }
            subs->emplace_back(std::stoi(s->substr(start, end - start)));
            start = end + 1;
        }
    }
};
