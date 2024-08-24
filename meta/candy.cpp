//
// Created by 62339 on 2023/10/8.
//
#include <vector>

class Candy {
public:
    int candy(std::vector<int> &ratings) {
        std::vector<int> can(ratings.size(), 0);

        for (int i = 0; i < ratings.size() - 1; ++i) {
            if (ratings[i] < ratings[i + 1]) {
                if (can[i] == 0) {
                    can[i] = 1;
                }
                can[i + 1] = can[i] + 1;
            }
        }
        if (can[ratings.size() - 1] == 0) {
            can[ratings.size() - 1] = 1;
        }

        int result = 0;
        for (int i = ratings.size() - 1; i > 0; --i) {
            if (can[i] == 0) {
                can[i] = 1;
            }

            if (ratings[i] < ratings[i - 1]) {

                can[i - 1] = std::max(can[i - 1], can[i] + 1);
            }
            result += can[i];
        }
        return can[0] == 0 ? result + 1 : result + can[0];
    }
};