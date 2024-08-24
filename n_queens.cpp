//
// Created by 62339 on 2023/10/12.
//
#include <vector>
#include <string>

class n_queens {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        board = std::vector<int>(n);
        result = std::vector<std::vector<std::string>>();
        _n = n;

        traverse(0, 0, 0, 0);
        return result;
    }

private:
    int _n;
    std::vector<int> board;
    std::vector<std::vector<std::string>> result;

    void traverse(int row, int col, int diagonal, int reverse) {
        if (row == _n) {
            std::vector<std::string> b;

            for (int i = 0; i < _n; ++i) {
                std::string temp;
                for (int j = 0; j < _n; ++j) {
                    temp += j == board[i] ? 'Q' : '.';
                }
                b.emplace_back(temp);
            }
            result.emplace_back(b);
            return;
        }

        int availablePositions = ((1 << _n) - 1) & (~(col | diagonal | reverse));
        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);
            availablePositions = availablePositions & (availablePositions - 1);
            int column = __builtin_ctz(position);
            board[row] = column;
            traverse(row + 1, col | position, (diagonal | position) >> 1, (reverse | position) << 1);
            board[row] = -1;
        }

    }
};