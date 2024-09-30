//
// Created by 62339 on 2023/11/26.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

class sliding_puzzle {
public:
    struct state {
        std::string cur;
        int step;
        std::vector<std::string> prev;

        int get_heuristic() {
            int result = 0;
            for (int i = 0; i < cur.size(); ++i) {
                int index = (cur[i] + 6 - '1') % 6;
                result += std::abs(i / 3 - index / 3) + std::abs(i % 3 - index % 3);
            }
            return result;
        }

        state(std::string& _cur, int _step): cur(_cur), step(_step) {};
    };
    int slidingPuzzle(std::vector<std::vector<int>>& board) {
        std::string b, target;
        std::unordered_set<std::string> visited;
        int m = board.size(), n = board[0].size(), t = 1;
        for (auto& row:board) {
            for (auto& num:row) {
                b += std::to_string(num);
                target += std::to_string(t);
                t = (t + 1) % (m * n);
            }
        }

        auto cmp = [](state a, state b) -> bool {
            return a.step + a.get_heuristic() > b.step + b.get_heuristic();
        };
        if (b == target) {return 0;}
        std::priority_queue<state, std::vector<state>, decltype(cmp)> pq;
        pq.emplace(b, 0);
        visited.emplace(b);

        auto find_zero = [](std::string& s) -> int {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '0') {
                    return i;
                }
            }
            return -1;
        };

        while (!pq.empty()) {
            state top = pq.top();
            pq.pop();


            int index = find_zero(top.cur);
            for (auto& dir:dirs[index]) {
                std::swap(top.cur[index], top.cur[dir]);

                if (visited.find(top.cur) == visited.end()) {
                    visited.emplace(top.cur);
                    state next_state(top.cur, top.step + 1);
                    if (top.cur == target) {
                        for (auto& s:top.prev) {
                            std::cout << s + ",";
                        }
                        return top.step + 1;
                    }
                    next_state.prev = std::vector<std::string>(top.prev.begin(), top.prev.end());
                    next_state.prev.emplace_back(top.cur);
                    pq.emplace(next_state);

                }
                std::swap(top.cur[index], top.cur[dir]);
            }
        }

        return -1;
    }

private:
    std::vector<std::vector<int>> dirs = {{1,3}, {0,2,4}, {1, 5},{0, 4}, {1,3,5}, {2, 4}};
};