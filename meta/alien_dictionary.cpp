//
// Created by 62339 on 2023/10/20.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
class alien_dictionary {
public:
    std::string alienOrder(std::vector<std::string>& words) {
        std::unordered_map<int, std::vector<int>> edges;
        std::unordered_set<int> dict;
        std::vector<int> in_degrees(26, 0);

        for (auto& word:words) {
            for (auto& ch:word) {
                dict.emplace(ch - 'a');
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            int j = 0;
            for (; j < std::min(words[i].size(), words[i+1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    if (edges.find(words[i][j] - 'a') == edges.end()) {
                        edges[words[i][j] - 'a'] = std::vector<int>();
                    }
                    edges[words[i][j] - 'a'].emplace_back(words[i + 1][j] - 'a');
                    in_degrees[words[i + 1][j] - 'a']++;
                    break;
                }
            }
            if (j == words[i + 1].size() && words[i].size() > words[i + 1].size()) {
                return "";
            }
        }

        std::string result(dict.size(), ' ');
        int index = 0;
        std::queue<int> q;

        for (int i = 0; i < 26; ++i) {
            if (in_degrees[i] == 0 && dict.find(i) != dict.end()) {
                q.push(i);
                result[index++] = (char)('a' + i);
            }
        }

        while (!q.empty()) {
            for (auto& n:edges[q.front()]) {
                in_degrees[n]--;
                if (in_degrees[n] == 0) {
                    q.push(n);
                    result[index++] = (char)('a' + n);
                }
            }
            q.pop();
        }

        return index == dict.size() ? result : "";
    }
};