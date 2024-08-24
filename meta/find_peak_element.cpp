//
// Created by 62339 on 2023/10/23.
//
#include <vector>
#include <iostream>

class find_peak_element{
public:
    int findPeakElement(std::vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if((mid == 0 ||nums[mid] > nums[mid - 1]) && (mid == nums.size() -1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }

    int find_local_min(std::vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if((mid == 0 ||nums[mid] < nums[mid - 1]) && (mid == nums.size() -1 || nums[mid] < nums[mid + 1])) {
                return mid;
            }
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};

//int main() {
//    find_peak_element a;
//    std::vector<int> t({1,2,3,1});
//    std::vector<int> t2({1,2,1,3,5,6,4});
//    std::vector<int> t3({4,3,2,1});
//    std::cout << a.find_local_min(t) << std::endl;
//    std::cout << a.find_local_min(t2) << std::endl;
//    std::cout << a.find_local_min(t3) << std::endl;
//}