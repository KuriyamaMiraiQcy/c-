//
// Created by 62339 on 2023/11/29.
//
#include <vector>
#include <queue>
class is_graph_bipartite {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        std::vector<int> vals(graph.size(), 0);

        std::queue<int> queue;
        for (int i = 0; i < graph.size(); ++i) {
            if (vals[i] == 0) {
                queue.emplace(i);
                vals[i] = 1;
                while (!queue.empty()) {
                    int f = queue.front();
                    queue.pop();
                    for (auto &n: graph[f]) {
                        if (vals[n] == 0) {
                            vals[n] = 3 - vals[f];
                            queue.emplace(n);
                        } else if (vals[n] == vals[f]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};