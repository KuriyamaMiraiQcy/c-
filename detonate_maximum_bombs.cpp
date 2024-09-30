//
// Created by 62339 on 2023/8/12.
//
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <iostream>

using namespace std;

class detonate_maximum_bombs {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = bombs.size();
        // 判断炸弹 u 能否引爆炸弹 v
        auto isConnected = [&](int u, int v) -> bool {
            long long dx = bombs[u][0] - bombs[v][0];
            long long dy = bombs[u][1] - bombs[v][1];
            return (long long) bombs[u][2] * bombs[u][2] >= dx * dx + dy * dy;
        };

        // 维护引爆关系有向图
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isConnected(i, j)) {
                    edges[i].push_back(j);
                }
            }
        }
        int res = 0;   // 最多引爆数量
        for (int i = 0; i < n; ++i) {
            // 遍历每个炸弹，广度优先搜索计算该炸弹可引爆的数量，并维护最大值
            vector<int> visited(n);
            int cnt = 1;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int cidx = q.front();
                q.pop();
                for (const int nidx: edges[cidx]) {
                    if (visited[nidx]) {
                        continue;
                    }
                    ++cnt;
                    q.push(nidx);
                    visited[nidx] = 1;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};

//int main() {
//    detonate_maximum_bombs a;
//    vector<int> b({1,2,3});
//    vector<int> c({2,3,1});
//    vector<int> d({3,4,2});
//    vector<int> e({4,5,3});
//    vector<int> g({5,6,4});
//    vector<vector<int>> f({c,b,d,e,g});
//    cout << a.maximumDetonation(f);
//}
