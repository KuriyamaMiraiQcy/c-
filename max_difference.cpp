//
// Created by 62339 on 2023/8/29.
//
#include <vector>
#include <algorithm>

class max_difference {
public:
    static int difference(std::vector<int> arr) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size() / 3;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        for (int i = arr.size() - 1; i >= arr.size() - n; --i) {
            sum -= arr[i];
        }
        return sum;
    }
};