//
// Created by 62339 on 2023/10/15.
//
#include <vector>
#include <stack>

class maximal_rectangle {
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        int l = matrix.size(), w = matrix[0].size();
        std::vector<std::vector<int>> left(matrix.size(), std::vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < w; ++j) {
                left[i][j] = matrix[i][j] == '1' && j > 0 ? left[i][j - 1] + 1 : matrix[i][j] - '0';
            }
        }

        int result = 0;
        for (int j = 0; j < w; ++j) {
            std::vector<int> up(l, 0), down(l, 0);

            std::stack<int> stack;
            for (int i = 0; i < l; ++i) {
                while (!stack.empty() && left[stack.top()][j] >= left[i][j]) {
                    stack.pop();
                }

                up[i] = stack.empty() ? -1 : stack.top();
                stack.push(i);
            }

            stack = std::stack<int>();
            for (int i = l - 1; i >= 0; --i) {
                while (!stack.empty() && left[stack.top()][j] >= left[i][j]) {
                    stack.pop();
                }

                down[i] = stack.empty() ? l : stack.top();
                stack.push(i);
            }

            for (int i = 0; i < l; ++i) {
                int length = down[i] - up[i] - 1;
                result = std::max(result, length * left[i][j]);
            }
        }
        return result;
    }
};