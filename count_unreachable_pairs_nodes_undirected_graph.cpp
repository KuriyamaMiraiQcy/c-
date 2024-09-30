//
// Created by 62339 on 2023/10/21.
//
#include <vector>
#include <functional>
class count_unreachable_pairs_nodes_undirected_graph {
public:
    long long countPairs(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        std::function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto union_ = [&](int x, int y) {
            int p_x = find(x);
            int p_y = find(y);
            if (p_x != p_y) {
                parent[p_x] = p_y;
            }
        };

        for (auto& edge:edges) {
            union_(edge[0], edge[1]);
        }

        long long result = 0;

        std::vector<int> count(n, 0);
        for (int i = 0; i < n; ++i) {
            count[parent[i]]++;
        }

        int start = 0, end = n - 1;
        while (start <= end) {
            if (count[start] == 0) {
                ++start;
                continue;
            }
            if (count[end] != 0) {
                --end;
                continue;
            }
            count[end] = count[start];
            count[start] = 0;
        }

        for (int i = start; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                result += count[i] * count[j];
            }
        }
        return result;
    }
};