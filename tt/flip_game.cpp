//
// Created by 62339 on 2023/11/25.
//
#include <vector>
#include <string>
#include <unordered_map>
class flip_game {
public:
    std::vector<std::string> generatePossibleNextMoves(std::string currentState) {
        std::unordered_map<char, char> map = {{'+','-'}, {'-', '+'}};
        std::vector<std::string> result;

        for (int i = 0; i < currentState.size() - 1; ++i) {
            if (currentState[i] == currentState[i + 1] && currentState[i] == '+') {
                currentState[i] = map[currentState[i]];
                currentState[i + 1] = map[currentState[i + 1]];
                result.emplace_back(currentState);
                currentState[i] = map[currentState[i]];
                currentState[i + 1] = map[currentState[i + 1]];
            }
        }
        return result;
    }
};