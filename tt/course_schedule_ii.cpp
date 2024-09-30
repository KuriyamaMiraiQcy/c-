//
// Created by 62339 on 2023/11/28.
//
#include <vector>
#include <queue>
class course_schedule_ii {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> in_degrees(numCourses);
        std::vector<std::vector<int>> edges(numCourses);

        for (auto& pre:prerequisites) {
            edges[pre[1]].emplace_back(pre[0]);
            in_degrees[pre[0]]++;
        }

        std::vector<int> result;
        std::queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (in_degrees[i] == 0) {
                q.emplace(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            result.emplace_back(front);

            for (auto& n:edges[front]) {
                in_degrees[n]--;
                if (in_degrees[n] == 0) {
                    q.emplace(n);
                }
            }
        }
        return result.size() == numCourses ? result : std::vector<int>();
    }
};