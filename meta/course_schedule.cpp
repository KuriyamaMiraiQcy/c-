//
// Created by 62339 on 2023/10/27.
//
#include <vector>
#include <queue>
#include <unordered_set>
class course_schedule {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> edges(numCourses, std::vector<int>());
        std::vector<int> in_degrees(numCourses, 0);

        for (auto& pre:prerequisites) {
            edges[pre[1]].emplace_back(pre[0]);
            ++in_degrees[pre[0]];
        }

        std::queue<int> queue;
        std::unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++i) {
            if (in_degrees[i] == 0) {
                queue.emplace(i);
                visited.emplace(i);
            }
        }


        while (!queue.empty()) {
            int top = queue.front();
            queue.pop();

            for (auto& n:edges[top]) {
                --in_degrees[n];
                if (visited.find(n) == visited.end() && in_degrees[n] == 0) {
                    queue.emplace(n);
                    visited.emplace(n);
                }
            }
        }
        return visited.size() == numCourses;
    }
};