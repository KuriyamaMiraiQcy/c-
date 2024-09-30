//
// Created by 62339 on 2023/10/20.
//
#include <vector>
class maximum_swap {
public:
    int maximumSwap(int num) {
        std::vector<int> arr;

        int max_index = 0;
        int index_1 = -1, index_2 = -1;
        while (num != 0) {
            arr.emplace_back(num % 10);
            if (num % 10 > arr[max_index]) {
                max_index = arr.size() - 1;
            } else if (num % 10 < arr[max_index]) {
                index_1 = arr.size() - 1;
                index_2 = max_index;
            }
            num /= 10;
        }

        if (index_1 != -1) {
            int temp = arr[index_1];
            arr[index_1] = arr[index_2];
            arr[index_2] = temp;
        }

        int result = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            result = result * 10 + arr[i];
        }
        return result;
    }
};