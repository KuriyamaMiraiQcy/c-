#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include "HtmlParser.cpp"

//
// Created by 62339 on 2023/8/27.
//
class web_crawler {
public:
    std::vector<std::string> crawl(std::string startUrl, HtmlParser htmlParser) {
        std::unordered_set<std::string> visited;
        std::queue<std::string> queue;
        queue.push(startUrl);
        std::string host = startUrl.substr(0, startUrl.find('/', 8));

        while (!queue.empty()) {
            std::string top = queue.front();
            queue.pop();

            visited.insert(top);
            for (std::string &url: htmlParser.getUrls(top)) {
                if (!visited.count(url) && url.find(host) == 0) {
                    queue.push(url);
                }
            }
        }
        return std::vector<std::string>(visited.begin(), visited.end());
    }

};