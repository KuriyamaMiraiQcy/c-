//
// Created by 62339 on 2023/11/1.
//
#include <vector>
#include <string>
#include <functional>
class word_search {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        auto is_valid = [&](int x, int y) -> bool {
            return x >= 0 && x < board.size() && y >= 0 && y < board[x].size();
        };
        std::function<bool(int, int, int)> dfs = [&](int x, int y, int index) -> bool {
            if (index == word.size() - 1) {
                return board[x][y] == word[index];
            }
            if (board[x][y] != word[index]) {
                return false;
            }
            char temp = board[x][y];
            board[x][y] = '\0';

            for (auto& dir:directions) {
                if (is_valid(x + dir[0], y + dir[1])) {
                    if (dfs(x + dir[0], y + dir[1], index + 1)) {
                        board[x][y] = temp;
                        return true;
                    }
                }
            }
            board[x][y] = temp;
            return false;
        };

        for (int x = 0; x < board.size(); ++x) {
            for (int y = 0; y < board[x].size(); ++y) {
                if (dfs(x, y, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};