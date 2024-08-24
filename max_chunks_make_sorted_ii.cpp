//
// Created by 62339 on 2023/10/15.
//
#include <vector>
#include <stack>

class max_chunks_make_sorted_ii {
public:
    int maxChunksToSorted(std::vector<int> &arr) {
        std::stack<int> stack;
        for (int i = 0; i < arr.size(); ++i) {
            if (stack.empty() || stack.top() <= arr[i]) {
                stack.push(arr[i]);
                continue;
            }
            int max = stack.top();
            while (!stack.empty() && stack.top() > arr[i]) {
                stack.pop();
            }
            stack.push(max);
        }
        return stack.size();
    }
};