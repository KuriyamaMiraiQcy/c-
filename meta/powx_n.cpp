#include <climits>

//
// Created by 62339 on 2023/11/2.
//
class powx_n {
public:
    double myPow(double x, int n) {
        return my_pow(x, (long long)n);
    }

    double my_pow(double x, long long n) {
        if (n < 0) {
            return 1 / my_pow(x, -n);
        }
        if (n == 0) {
            return 1.0;
        }
        double half = my_pow(x, n / 2);
        return n % 2 == 0? half * half: half * half * x;
    }

    double myPow1(double x, int n) {
        if (n == INT_MIN) {
            double half = myPow1(x, n / 2);
            return half * half;
        }
        if (n < 0) {
            return 1 / myPow1(x, -n);
        }
        double res = 1;
        while (n != 0) {
            if ((n & 1) == 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }
};