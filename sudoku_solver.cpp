//
// Created by 62339 on 2023/9/23.
//
#include <vector>
#include <unordered_set>

class sudoku_solver {
private:
    const std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::unordered_set<int>> nines, rows, cols;

    int get_nines(int x, int y) {
        return x / 3 * 3 + y / 3;
    }


    bool solve(std::vector<std::vector<char>> &board, int x, int y) {
        if (x == 9) {
            return true;
        }
        int next_y = (y + 1) % 9;
        int next_x = next_y == 0 ? x + 1 : x;

        if (board[x][y] != '.') {
            return solve(board, next_x, next_y);
        }

        std::unordered_set<int> answers(numbers.begin(), numbers.end());
        auto get_answer = [&](std::unordered_set<int> &exist) -> void {
            for (int n: exist) {
                answers.erase(n);
            }
        };

        get_answer(nines[get_nines(x, y)]);
        get_answer(rows[x]);
        get_answer(cols[y]);

        if (answers.empty()) {
            return false;
        }

        for (int n: answers) {
            board[x][y] = (char) ('0' + n);
            nines[get_nines(x, y)].insert(n);
            rows[x].insert(n);
            cols[y].insert(n);
            if (solve(board, next_x, next_y)) {
                return true;
            }
            board[x][y] = '.';
            nines[get_nines(x, y)].erase(n);
            rows[x].erase(n);
            cols[y].erase(n);
        }
        return false;
    }

public:
    void solveSudoku(std::vector<std::vector<char>> &board) {
        nines = std::vector<std::unordered_set<int>>(9, std::unordered_set<int>());
        rows = std::vector<std::unordered_set<int>>(9, std::unordered_set<int>());
        cols = std::vector<std::unordered_set<int>>(9, std::unordered_set<int>());

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    nines[get_nines(i, j)].insert(n);
                    rows[i].insert(n);
                    cols[j].insert(n);
                }
            }
        }

        solve(board, 0, 0);
    }

};