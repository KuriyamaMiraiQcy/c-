//
// Created by 62339 on 2023/8/19.
//
#include <cmath>

using namespace std;

class number_digit_one {
public:
    int countDigitOne(int n) {
        int start = 1;
        int count = 0;
        while (start <= n) {
            int times = n / start / 10;
            count += times * start;
            int mod = n - times * start * 10;
            count += min(max(mod - start + 1, 0), start);
            if (start < INT_MAX / 10) {
                start *= 10;
            } else {
                break;
            }
        }
        return count;
    }
};
