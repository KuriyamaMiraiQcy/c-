//
// Created by 62339 on 2023/11/18.
//
#include <vector>
class cutting_ribbons {
public:
    int maxLength(std::vector<int>& ribbons, int k) {
        int sum = 0;
        for (auto& n:ribbons) {
            sum += n;
        }
        if (k > sum) {
            return 0;
        }
        auto check = [&](int n) -> bool {
            int count = 0;
            for (auto& r:ribbons) {
                count += r / n;
            }
            return count >= k;
        };
        int start = 1, end = sum /k + 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (!check(mid)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};