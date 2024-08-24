//
// Created by 62339 on 2023/9/5.
//
#include <vector>
#include <iostream>

class interview_nv {
public:
    std::vector<int> merge_list(std::vector<int> l1, std::vector<int> l2) {
        std::vector<int> result(l1.size() + l2.size());

        int p1 = 0, p2 = 0, count = 0;
        while (p1 < l1.size() && p2 < l2.size()) {
            if (l1[p1] < l2[p2]) {
                result[count++] = l1[p1++];
            } else {
                result[count++] = l2[p2++];
            }
        }
        while (count < result.size()) result[count++] = p1 < l1.size() ? l1[p1++] : l2[p2++];
        return result;
    }


};

//int main () {
//    std::vector<int> l1({1,3,7,9,11});
//    std::vector<int> l2({2,3,5,8,12});
//    interview_nv a;
//    for (auto& p:a.merge_list(l1, l2)) {
//        std::cout << p << " ";
//    }
//}