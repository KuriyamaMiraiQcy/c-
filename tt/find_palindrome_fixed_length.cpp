//
// Created by 62339 on 2023/11/26.
//
#include <vector>
#include <cmath>
#include <string>

class find_palindrome_fixed_length {
public:
    std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength) {
        int half_len = (intLength + 1) / 2;
        int start = std::pow(10, half_len - 1) - 1;
        int end = std::pow(10, half_len) - 1;
        std::vector<long long> result;

        auto recon = [&](int i)-> long long {
            if (start + i > end) {
                return -1;
            }
            std::string s = std::to_string(start + i);
            if (intLength % 2 == 1) {
                for (int j = s.size() - 2; j >= 0; --j) {
                    s += s[j];
                }
            } else {
                for (int j = s.size() - 1; j >= 0; --j) {
                    s += s[j];
                }
            }
            return stoll(s);
        };

        for (auto& query:queries) {
            result.emplace_back(recon(query));
        }
        return result;
    }
};