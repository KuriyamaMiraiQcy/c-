//
// Created by 62339 on 2023/8/16.
//
#include <vector>

using namespace std;

class losers_circular_game {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> friends(n, false);
        for (int i = 0, j = k; !friends[i]; j += k) {
            friends[i] = true;
            i = (i + j) % n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!friends[i]) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};