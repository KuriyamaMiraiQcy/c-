          //
// Created by 62339 on 2023/9/4.
//
#include <vector>
class counting_bits {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> result(n + 1, 0);
        int high = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & i - 1) == 0) {
                high = 1;
            }
            result[i] = result[i - high] + 1;
        }

        return result;
    }
};