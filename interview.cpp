//
// Created by 62339 on 2023/8/30.
//
// nxn
// 123
// 456
// 789
// 124753689
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// 1 2 5 9 6 3 4 7 10 13 14 11 8 12 15 16
#include <iostream>
#include <vector>

class interview {
public:
    void output_array(int n) {
        int start_x = 0, start_y = 0;
        bool up = true;

        auto find_next = [&]() -> void {
            if (up) {
                if (start_y == n - 1) {
                    ++start_x;
                } else {
                    ++start_y;
                }
                return;
            }
            if (start_x == n - 1) {
                ++start_y;
            } else {
                ++start_x;
            }
        };

        while (start_x * n + start_y != n * n - 1) {
            output_number(start_x, start_y, n);
            if (up) {
                if (start_x == 0 || start_y == n - 1) {
                    find_next();
                    up = !up;
                } else {
                    --start_x;
                    ++start_y;
                }
                continue;
            }
            if (start_x == n - 1 || start_y == 0) {
                find_next();
                up = !up;
            } else {
                ++start_x;
                --start_y;
            }
        }
        output_number(n - 1, n - 1, n);
    }

    void output_number(int x, int y, int n) {
        std::cout << (x * n + y + 1) << " ";
    }
};

std::vector<int> fib(int n) {
    std::vector<int> result(n);
    if (n <= 0) return std::vector<int>();
    result[0] = 0;
    if (n == 1) return result;
    result[1] = 1;
    for (int i = 2; i < n; ++i) {
        result[i] = result[i - 1] + result[i - 2];
    }
    for (int i: result) {
        std::cout << i << ' ';
    }
    return result;
}
