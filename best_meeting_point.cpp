//
// Created by 62339 on 2023/10/17.
//
#include <vector>

class best_meeting_point {
public:
    int minTotalDistance(std::vector<std::vector<int>> &grid) {
        std::vector<int> cols, rows;
        for (int j = 0; j < grid[0].size(); ++j) {
            for (int i = 0; i < grid.size(); ++i) {
                if (grid[i][j] == 1) {
                    cols.emplace_back(j);
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.emplace_back(i);
                }
            }
        }

        return cal_dis(cols) + cal_dis(rows);
    }

private:
    int cal_dis(std::vector<int> &vec) {
        int start = 0, end = vec.size() - 1;
        int result = 0;
        while (start < end) {
            result += vec[end--] - vec[start++];
        }
        return result;
    }
};