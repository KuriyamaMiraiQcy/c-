#include <string>
#include <vector>

//
// Created by 62339 on 2023/8/27.
//
class HtmlParser {
public:
    virtual std::vector<std::string> getUrls(std::string url) {
        return {};
    }
};