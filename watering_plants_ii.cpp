//
// Created by 62339 on 2024/5/9.
//
#include <vector>
class watering_plants_ii {
public:
    int minimumRefill(std::vector<int>& plants, int capacityA, int capacityB) {
        int start = 0, end = plants.size() - 1, result = 0;
        int refillA = capacityA, refillB = capacityB;

        while (start < end) {
            if (plants[start] > capacityA) {
                result++;
                capacityA = refillA;
            }
            capacityA -= plants[start++];
            if (plants[end] > capacityB) {
                result++;
                capacityB = refillB;
            }
            capacityB -= plants[end--];
        }
        if (start == end) {
            result += std::max(capacityA, capacityB) < plants[start] ? 1 : 0;
        }
        return result;
    }
};