//
// Created by 62339 on 2023/10/21.
//
#include <vector>
#include <functional>
#include <iostream>

class kth_largest_element {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::function<int(int, int)> quick_select = [&](int start, int end) -> int {
            if (start == end) {
                return nums[nums.size() - k];
            }
            int pivot = nums[start];

            int e = end;
            for (int i = end; i > start; i--) {
                if (nums[i] > pivot) {
                    int temp = nums[e];
                    nums[e] = nums[i];
                    nums[i] = temp;
                    e--;
                }
            }
            nums[start] = nums[e];
            nums[e] = pivot;

            if (e == nums.size() - k) return pivot;
            if (e > nums.size() - k) return quick_select(start, e - 1);
            return quick_select(e + 1, end);
        };

        return quick_select(0, nums.size() - 1);
    }

};

//int main() {
//    kth_largest_element a;
//    std::vector<int> b({3,2,3,1,2,4,5,5,6});
//    std::cout << a.findKthLargest(b,4);
//}