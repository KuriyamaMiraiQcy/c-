//
// Created by 62339 on 2023/9/22.
//
#include <vector>

class count_primes {
public:
    int countPrimes(int n) {
        std::vector<int> nums(n, 1);

        for (int i = 2; i < n; ++i) {
            for (int j = 2; j * i < n; ++j) {
                nums[i * j] = 0;
            }
        }

        int result = 0;
        for (int i = 2; i < n; ++i) {
            result += nums[i];
        }
        return result;
    }
};