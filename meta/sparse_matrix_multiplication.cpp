//
// Created by 62339 on 2023/11/2.
//
#include <vector>
class sparse_matrix_multiplication {
public:
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
        std::vector<std::vector<std::pair<int, int>>> m1(mat1.size());
        std::vector<std::vector<std::pair<int, int>>> m2(mat2[0].size());
        for (int i = 0; i < mat1.size(); ++i) {
            for (int j = 0; j < mat1[i].size(); ++j) {
                if (mat1[i][j] != 0) {
                    m1[i].emplace_back(j,mat1[i][j]);
                }
            }
        }

        for (int j = 0; j < mat2[0].size(); ++j) {
            for (int i = 0; i < mat2.size(); ++i) {
                if (mat2[i][j] != 0) {
                    m2[j].emplace_back(i,mat2[i][j]);
                }
            }
        }

        std::vector<std::vector<int>> result(mat1.size(), std::vector<int>(mat2[0].size(), 0));

        for (int i = 0; i < m1.size(); ++i) {
            for (int j = 0; j < m2.size(); ++j) {
                int p1 = 0, p2 = 0, res = 0;
                while (p1 < m1[i].size() && p2 < m2[j].size()) {
                    if (m1[i][p1].first < m2[j][p2].first) {
                        ++p1;
                        continue;
                    }
                    if (m1[i][p1].first > m2[j][p2].first) {
                        ++p2;
                        continue;
                    }
                    res += m1[i][p1++].second * m2[j][p2++].second;
                }
                result[i][j] = res;
            }
        }
        return result;

    }
};