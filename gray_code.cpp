//
// Created by 62339 on 2024/5/14.
//
#include <vector>
#include <cmath>

class gray_code {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result(2, 0);
        result[1] = 1;

        for (int i = 1; i < n; ++i) {
            int j = result.size() - 1;
            int po = pow(2, i);
            for (; j >= 0; --j) {
                result.emplace_back(result[j] + po);
            }
        }
        return result;
    }
};