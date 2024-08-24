//
// Created by 62339 on 2023/10/15.
//
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

class word_ladder {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string> &wordList) {
        int end = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            end = wordList[i] == endWord ? i : end;
        }

        if (end == -1) {
            return 0;
        }
        std::vector<std::vector<int>> adj(wordList.size() + 1, std::vector<int>());

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j <= wordList.size(); ++j) {
                if (is_one_difference(wordList[i], j == wordList.size() ? beginWord : wordList[j])) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }

        std::queue<int> queue;
        std::vector<int> dis(wordList.size() + 1, INT_MAX);
        queue.emplace(wordList.size());
        dis[wordList.size()] = 1;

        while (!queue.empty()) {
            int top = queue.front();
            if (top == end) {
                return dis[end];
            }
            queue.pop();

            for (int n: adj[top]) {
                if (dis[n] == INT_MAX) {
                    dis[n] = dis[top] + 1;
                    queue.push(n);
                }
            }
        }
        return 0;
    }

private:
    static bool is_one_difference(std::string a, std::string b) {
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            count += a[i] != b[i];
        }
        return count == 1;
    }
};