//
// Created by 62339 on 2023/9/11.
//
#include <vector>

class next_greater_element_iv {
public:
    std::vector<int> secondGreaterElement(std::vector<int> &nums) {
        std::vector<int> result(nums.size(), -1), s1, s2;
        for (int i = 0; i < nums.size(); ++i) {
            while (!s2.empty() && nums[s2.back()] < nums[i]) {
                result[s2.back()] = nums[i];
                s2.pop_back();
            }
            int l = s1.size() - 1;
            while (!s1.empty() && nums[s1[l]] < nums[i]) {
                l--;
            }
            s2.insert(s2.end(), s1.begin() + l + 1, s1.end());
            s1.emplace_back(i);
        }
        return result;
    }
};