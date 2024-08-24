//
// Created by 62339 on 2023/10/30.
//
#include <vector>
class h_index_ii {
public:
    int hIndex(std::vector<int>& citations) {
        int n = citations.size();
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (citations[mid] >= citations.size() - mid) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return n - start;
    }
};