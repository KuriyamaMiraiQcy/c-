//
// Created by 62339 on 2023/11/26.
//
#include <vector>
class jump_game {
public:
    bool canJump(std::vector<int>& nums) {
        int left = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i <= left && i + nums[i] >= left) {
                left = i;
            }
        }
        return left == 0;
    }
};