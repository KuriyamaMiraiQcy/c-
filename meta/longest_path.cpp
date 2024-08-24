//
// Created by 62339 on 2023/10/26.
//
#include <vector>
#include <queue>
class longest_path {
public:
    std::vector<std::vector<int>> treeDiameter(std::vector<std::vector<int>>& _edges, int i) {
        edges = std::vector<std::vector<int>>(_edges.size() + 1, std::vector<int>());
        for (auto& arr:_edges) {
            edges[arr[0]].emplace_back(arr[1]);
            edges[arr[1]].emplace_back(arr[0]);
        }
        visited = std::vector<int>(edges.size(), -1);
        std::vector<int> deepest = bfs(i);

        for (auto& n:deepest) {
            visited = std::vector<int>(edges.size(), 0);
            dfs(n);
        }
        return result;
    }
private:
    std::vector<std::vector<int>> edges, result;
    std::vector<int> visited, path;
    int d = 0;
    std::vector<int> bfs(int index) {
        std::queue<std::pair<int, int>> q;
        q.emplace(index, 0);
        visited[index] = 0;

        while (!q.empty()) {
            for (auto& n:edges[q.front().first]) {
                if (visited[n] == -1) {
                    q.emplace(n, q.front().second + 1);
                    visited[n] = q.front().second + 1;
                }
            }
            q.pop();
        }

        std::vector<int> deepest;
        int depth = 0;
        for(int i = 0; i < visited.size();++i) {
            if (visited[i] > depth) {
                deepest = std::vector<int>({i});
                depth = visited[i];
            } else if (visited[i] == depth) {
                deepest.emplace_back(i);
            }
        }
        return deepest;
    }

    void dfs(int i) {
        path.emplace_back(i);
        visited[i] = 1;
        bool is_end = true;
        for (auto& n:edges[i]) {
            if (!visited[n]) {
                dfs(n);
                is_end = false;
            }
        }
        if (is_end) {
            if (path.size() > d) {
                result = std::vector<std::vector<int>>({path});
                d = path.size();
            } else if (path.size() == d) {
                result.emplace_back(path);
            }
        }
        path.pop_back();
    }
};

//int main() {
//    longest_path a;
//    std::vector<std::vector<int>> t({{0,1},{1,2},{2,3},{1,4},{4,5}});
//    a.treeDiameter(t, 1);
//}