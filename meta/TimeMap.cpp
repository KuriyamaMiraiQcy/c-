//
// Created by 62339 on 2023/11/5.
//
#include <unordered_map>
#include <vector>
#include <string>
class TimeMap {
public:
    TimeMap() {

    }

    void set(std::string key, std::string value, int timestamp) {
        stores[key].emplace_back(timestamp, value);
    }

    std::string get(std::string key, int timestamp) {
        int start = 0, end = stores[key].size();

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (stores[key][mid].first < timestamp+1) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start == 0 ? "" : stores[key][start - 1].second;
    }
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> stores;
};