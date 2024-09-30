//
// Created by 62339 on 2024/5/7.
//
class the_kth_factor_n {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        for (; i * i < n; ++i) {
            if (n % i == 0) {
                k--;
            }
            if (k == 0) {
                return i;
            }
        }
        if(i * i != n) {
            i --;
        }
        for (; i >= 1; --i) {
            if (n % i == 0) {
                k--;
            }
            if (k == 0) {
                return n / i;
            }
        }
        return -1;
    }
};