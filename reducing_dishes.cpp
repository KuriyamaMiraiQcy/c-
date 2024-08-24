//
// Created by 62339 on 2023/10/22.
//
#include <vector>
#include <algorithm>
class reducing_dishes {
public:
    int maxSatisfaction(std::vector<int>& satisfaction) {
        std::sort(satisfaction.begin(), satisfaction.end());

        int sum = 0, i = satisfaction.size() - 1;
        for (; i >= 0; --i) {
            if (satisfaction[i] >= 0) {
                sum += satisfaction[i];
            } else {
                break;
            }
        }
        int prev_sum = 0;
        for (int j = i; j >= -1; --j) {
            if (j >= 0 && prev_sum + satisfaction[j] + sum >= 0) {
                prev_sum += satisfaction[j];
            } else {
                int result = 0;
                for (int k = 1; j + k < satisfaction.size(); ++k) {
                    result += k * satisfaction[j + k];
                }
                return result;
            }
        }
        return 0;
    }
};