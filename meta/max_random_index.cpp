//
// Created by 62339 on 2023/10/31.
//
#include <vector>
#include <climits>
#include <cstdlib>

class max_random_index {
public:
    explicit max_random_index(std::vector<int>& _nums):nums{_nums} {};

    int get_index() {
        if (cur == nums.size()) {
            return index;
        }
        ++cur;
        if (nums[cur - 1] > max) {
            max = nums[cur - 1];
            index = cur - 1;
            count = 1;
        } else if (nums[cur - 1] == max) {
            ++count;
            if (rand() % count == 0) {
                index = cur - 1;
            }
        }
        return index;
    }
private:
    std::vector<int> nums;
    int cur = 0, max = INT_MIN, index = 0, count = 0;
};