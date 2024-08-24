//
// Created by 62339 on 2023/8/19.
//
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class cycle {
public:
    bool is_cycled(int n, vector<vector<int>> edges) {
        unordered_set<int> visited;
        vector<int> in_degrees(n);
        for (int i = 0; i < edges.size(); ++i) {
            for (int j: edges[i]) {
                ++in_degrees[j];
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degrees[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            visited.emplace(top);
            for (int j: edges[top]) {
                --in_degrees[j];
                if (in_degrees[j] == 0) {
                    q.push(j);
                }
            }
        }
        return visited.size() == n;
    }
};
