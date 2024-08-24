#include <cmath>

//
// Created by 62339 on 2023/8/25.
//
class k_smallest_lexicographical_order {
public:
    int findKthNumber(int n, int k) {
        int base = 1;
        while (!k) {
            int count = count_number(base, n);
            if (count < k) {
                k -= count;
                ++base;
            } else {
                base *= 10;
                --k;
            }
        }
        return base;
    }

    int count_number(int cur, int n) {
        int count = 1;
        int low = cur, high = cur;
        while (high <= n && low < INT_MAX / 10) {
            count += std::min(high - low + 1, n);
            low *= 10;
            high = high * 10 + 9;
        }
        return count;
    }
};