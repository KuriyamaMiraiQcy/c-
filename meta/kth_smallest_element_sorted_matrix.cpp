//
// Created by 62339 on 2023/11/1.
//
#include <vector>
class kth_smallest_element_sorted_matrix {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int start = matrix[0][0], end = matrix[matrix.size() -1][matrix.size() -1] + 1;

        auto count = [&](int mid) -> int {
            int res = 0;
            int x = matrix.size() - 1;
            int y = 0;
            while (x >= 0 && y < matrix.size()) {
                if (matrix[x][y] <= mid) {
                    res += x + 1;
                    ++y;
                } else {
                    --x;
                }
            }
            return res;
        };

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (count(mid) >= k) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};