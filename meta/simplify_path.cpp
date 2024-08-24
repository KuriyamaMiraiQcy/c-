//
// Created by 62339 on 2023/10/19.
//
#include <string>
#include <vector>

class simplify_path {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> queue;
        queue.emplace_back("/");

        int prev = 0;
        auto handle_range = [&](int i) {
            std::string repo;
            for (int j = prev + 1; j < i; ++j) {
                repo += path[j];
            }
            prev = i;
            if (repo == ".." && queue.size() > 1) {
                queue.pop_back();
            } else if (repo != "." && repo != "..") {
                queue.emplace_back(repo);
            }
        };
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (path[i - 1] != '/') {
                    handle_range(i);
                }
                prev = i;
            }

        }
        if (prev != path.size() - 1) {
            handle_range(path.size());
        }

        std::string result = "/";
        for (int i = 1; i < queue.size(); ++i) {
            result += queue[i] + "/";
        }
        return result.size() > 1 ? result.substr(0, result.size() - 1) : result;
    }
};