//
// Created by 62339 on 2023/9/4.
//
class minimum_operations_reduce_to_0 {
public:
    int minOperations(int n) {
        int count = 0, result = 0;
        while (n) {
            if (n & 1) {
                ++count;
            } else {
                result += count > 0 ? 1 : 0;
                count = count > 1 ? 1 : 0;
            }
            n >>= 1;
        }
        if (count == 1) {
            ++result;
        } else {
            result += 2;
        }
        return result;
    }
};