//
// Created by 62339 on 2023/11/2.
//
#include <string>
#include <unordered_map>
class bulls_and_cows {
public:
    std::string getHint(std::string secret, std::string guess) {
        std::unordered_map<char, int> map;
        int a_num = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++a_num;
            } else {
                ++map[secret[i]];
            }
        }

        int b_num = 0;
        for (int i = 0; i < guess.size(); ++i) {
            if (secret[i] != guess[i] && map.find(guess[i]) != map.end()) {
                ++b_num;
                --map[guess[i]];
                if (map[guess[i]] == 0) {
                    map.erase(guess[i]);
                }
            }
        }

        return std::to_string(a_num) + "A" + std::to_string(b_num) + "B";
    }
};