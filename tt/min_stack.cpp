//
// Created by 62339 on 2023/11/24.
//
#include <stack>
#include <climits>

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        min = std::min(min, val);
        max = std::max(max, val);
        stack.push(val);
        vals.emplace(min, max);
    }

    void pop() {
        stack.pop();
        vals.pop();
        if (vals.empty()) {
            min = INT_MAX;
            max = INT_MAX;
        } else {
            min = vals.top().first;
            max = vals.top().second;
        }
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return vals.top().first;
    }

    int getMax() {
        return vals.top().second;
    }
private:
    std::stack<int> stack;
    std::stack<std::pair<int, int>> vals;
    int min = INT_MAX, max = INT_MIN;
};