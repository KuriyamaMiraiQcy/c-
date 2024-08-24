//
// Created by 62339 on 2024/5/14.
//
#include <string>
#include <vector>
#include <cmath>
class minimum_unique_word_abbreviation {
public:
    std::string minAbbreviation(std::string target, std::vector<std::string>& dictionary) {
        std::vector<int> bit;
        bool need_abb = false;
        for (auto& dic:dictionary) {
            if (dic.size() != target.size()) {
                continue;
            }
            need_abb = true;
            int mask = 0;
            for (int i = 0; i < target.size(); ++i) {
                if (target[i] != dic[i]) {
                    mask += 1 << i;
                }
            }
            bit.emplace_back(mask);
        }

        if (!need_abb) {
            return std::to_string(target.size());
        }
        int len = target.size();
        std::string result = target;
        for (int i = 0; i < std::pow(2, target.size()); ++i) {
            bool is_valid = true;
            for (auto& m:bit) {
                is_valid &= (i & m) > 0;
            }
            std::string s;
            if (is_valid) {
                int prev = -1;
                for (int j = 0; j < target.size(); ++j) {
                    if (((i >> j) & 1) == 1) {
                        if (prev == - 1) {
                            if (j != 0) {
                                s += std::to_string(j);
                            }
                            s += target[j];
                        } else {
                            if (j - prev > 1) {
                                s += std::to_string(j - prev - 1);
                            }
                            s += target[j];
                        }
                        prev = j;
                    }
                }
                if (prev != target.size() - 1) {
                    s += std::to_string(target.size() - 1 - prev);
                }
                if (s.size() < len) {
                    len = s.size();
                    result = s;
                }
            }

        }
        return result;
    }
};