//
// Created by 62339 on 2023/11/1.
//
#include <queue>
class MovingAverage {
public:
    MovingAverage(int size) {
        _size = size;
    }

    double next(int val) {
        nums.emplace(val);
        sum += val;
        if (cur < _size) {
            cur++;
        } else {
            sum -= nums.front();
            nums.pop();
        }
        return (double) sum / cur;
    }

private:
    std::queue<int> nums;
    int _size;
    int cur = 0;
    int sum = 0;
};