#include <valarray>
#include <string>
//
// Created by 62339 on 2023/11/17.
//
class nth_digit {
public:
    int findNthDigit(int n) {
        long long level = 1;
        long long base = 1;
        long long sum = 9 * level * base;

        while (n > sum) {
            n -= sum;
            ++level;
            base *= 10;
            sum = 9 * level * base;
        }

        --n;
        int mod = n % level;
        n /= level;
        base += n;
        std::string s = std::to_string(base);

        return s[mod] - '0';
    }
};