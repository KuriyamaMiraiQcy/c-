//
// Created by 62339 on 2023/10/29.
//
#include <cmath>
class sum_square_numbers {
public:
    bool judgeSquareSum(int c) {
        int sq_rt = std::sqrt(c);
        int start = 0, end = sq_rt;

        while (start <= end) {
            if (pow(start, 2) + pow(end, 2) == c) {
                return true;
            }
            if (pow(start, 2) + pow(end, 2) < c) {
                ++start;
            } else {
                --end;
            }
        }
        return false;
    }
};