//
// Created by 62339 on 2023/11/28.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class bus_routes {
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        std::vector<std::vector<int>> edge(routes.size());
        std::unordered_map<int, std::vector<int>> stop;
        std::vector<int> start;
        std::unordered_set<int> end;

        for (int i = 0; i < routes.size(); ++i) {
            for (auto& s:routes[i]) {
                for (auto& bus:stop[s]) {
                    edge[i].emplace_back(bus);
                    edge[bus].emplace_back(i);
                }
                stop[s].emplace_back(i);
                if (s == source) {
                    start.emplace_back(i);
                }
                if (s == target) {
                    end.emplace(i);
                }
            }
        }
        std::queue<int> q, num;
        std::vector<int> visited(routes.size(), 0);
        for (auto& route:start) {
            visited[route] = 1;
            q.emplace(route);
            num.emplace(1);
            if (end.find(route) != end.end()) {
                return 1;
            }
        }

        while (!q.empty()) {
            int front = q.front();
            int dis = num.front();
            q.pop();
            num.pop();

            for (auto& n:edge[front]) {
                if (!visited[n]) {
                    if (end.find(n) != end.end()) {
                        return dis + 1;
                    }
                    visited[n] = 1;
                    q.emplace(n);
                    num.emplace(dis + 1);
                }
            }
        }
        return -1;

    }
};