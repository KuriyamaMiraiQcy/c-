//
// Created by 62339 on 2023/11/2.
//
#include <vector>
#include <cstdlib>

class random_pick_with_weight {
public:
    random_pick_with_weight(std::vector<int>& w) {
        weight = std::vector<int>(w.size(), 0);
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            weight[i] = sum;
        }
    }

    int pickIndex() {
        int n = std::rand() % sum + 1;
        int start = 0, end = weight.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (weight[mid] < n) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
private:
    std::vector<int> weight;
    int sum = 0;
};