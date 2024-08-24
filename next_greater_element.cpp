//
// Created by 62339 on 2023/9/10.
//
#include <vector>
#include <stack>

class next_greater_element {
public:
    std::vector<int> nextGreaterElements(std::vector<int> &nums) {
        std::stack<int> decreasing_stack;
        std::vector<int> result(nums.size(), -1);
        int length = nums.size();
        for (int i = 0; i < nums.size() * 2 - 1; ++i) {
            decreasing_stack.push(i);
            if (nums[i % length] <= nums[(i + 1) % length]) {
                bool is_update = decreasing_stack.size() < length;
                while (!decreasing_stack.empty() && nums[decreasing_stack.top() % length] < nums[(i + 1) % length]) {
                    result[decreasing_stack.top() % length] = is_update ? nums[(i + 1) % length] : -1;
                    decreasing_stack.pop();
                }
            }
        }
        return result;
    }
};