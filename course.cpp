//
// Created by 62339 on 2023/8/19.
//
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class course {
public:
    vector<int> earliest_time(vector<vector<int>> courses, vector<int> time) {
        vector<int> in_degree(courses.size());
        for (int i = 0; i < courses.size(); i++) {
            for (int j: courses[i]) {
                in_degree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < courses.size(); i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        int dummy = -1;
        q.push(dummy);

        vector<int> result(courses.size());
        int start_time = 0;
        int end_time = 0;
        while (!q.empty()) {
            int first = q.front();
            q.pop();
            if (first == -1) {
                start_time = end_time;
                continue;
            }
            result[first] = start_time + time[first];
            end_time = max(end_time, start_time + time[first]);
            for (int j: courses[first]) {
                in_degree[j]--;
                if (in_degree[j] == 0) {
                    q.push(j);
                }
            }
        }
        return result;
    }
};
