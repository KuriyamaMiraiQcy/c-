//
// Created by 62339 on 2023/11/24.
//
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

class number_good_paths {
public:
    int numberOfGoodPaths(std::vector<int>& vals, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> neighbors(vals.size());

        for (auto& edge:edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }

        std::vector<int> id(vals.size()), parent(vals.size()), size(vals.size(), 1);
        std::iota(id.begin(), id.end(), 0);
        std::iota(parent.begin(), parent.end(), 0);
        std::stable_sort(id.begin(), id.end(), [&](int i, int j) -> bool {
           return vals[i] < vals[j];
        });

        std::function<int(int)> find = [&](int i)-> int {
            if (parent[i] != i) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        };

        int result = vals.size();
        for (int i:id) {
            int p = find(i);
            for (auto& n:neighbors[i]) {
                int p_n = find(n);
                if (vals[p_n] > vals[i] || p_n == p) {
                    continue;
                }
                if (vals[p_n] == vals[i]) {
                    result += size[p] * size[p_n];
                    size[p] += size[p_n];
                }
                parent[p_n] = p;
            }
        }
        return result;
    }
};