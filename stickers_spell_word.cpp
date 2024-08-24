//
// Created by 62339 on 2023/10/17.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

class stickers_spell_word {
public:
    int minStickers(std::vector<std::string> &stickers, std::string target) {
        std::queue<std::pair<int, int>> queue;
        queue.emplace(0, 0);
        std::unordered_set<int> visited;
        visited.emplace(0);

        while (!queue.empty()) {
            std::pair<int, int> top = queue.front();
            if (top.first == (1 << target.size()) - 1) {
                return top.second;
            }

            queue.pop();
            visited.emplace(top.first);

            for (auto &sticker: stickers) {
                std::vector<int> count(26, 0);
                int num = top.first;

                for (int i = 0; i < sticker.size(); ++i) {
                    count[sticker[i] - 'a']++;
                }

                for (int i = 0; i < target.size(); ++i) {
                    if (((num >> i) & 1) == 0 && count[target[i] - 'a'] > 0) {
                        count[target[i]]--;
                        num |= (1 << i);
                    }
                }

                if (num != top.first && visited.find(num) == visited.end()) {
                    queue.emplace(num, top.second + 1);
                    visited.emplace(num);
                }
            }
        }
        return -1;
    }
};

//int main() {
//    stickers_spell_word a;
//    std::vector<std::string> b({"with", "example", "science"});
//    std::cout << a.minStickers(b, "thehat");
//}