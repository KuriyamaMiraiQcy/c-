//
// Created by 62339 on 2023/10/30.
//
#include <vector>
#include <algorithm>
#include <queue>
class meeting_rooms_ii {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int result = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (auto& interval:intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.emplace(interval[1]);
            result = std::max(result, (int)pq.size());
        }
        return result;
    }
};