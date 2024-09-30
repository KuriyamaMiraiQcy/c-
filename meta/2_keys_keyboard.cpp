//
// Created by 62339 on 2023/10/30.
//
class two_keys_keyboard {
public:
    int minSteps(int n) {
        int result = 0;
        for (int i = 2; i * i <= n; i++) {
            while (n / i == 0) {
                result += i;
                n /= i;
            }
        }
        if (n > 1) {
            result += n;
        }
        return result;
    }
};