//
// Created by 62339 on 2023/10/23.
//
#include <string>
#include <vector>
#include <stack>
class smallest_subsequence_distinct_characters {
public:
    std::string smallestSubsequence(std::string s) {
        std::vector<int> count(26, 0), used(26, 0);
        for (auto& ch:s) {
            count[ch - 'a']++;
        }

        std::stack<int> result;
        for (auto& ch:s) {
            count[ch - 'a']--;
            if (used[ch - 'a'] == 0) {
                while (!result.empty() && result.top() > ch - 'a' && count[result.top()] > 0) {
                    used[result.top()] = 0;
                    result.pop();
                }
                result.push(ch - 'a');
                used[ch - 'a'] = 1;
            }
        }

        std::string res;
        while (!result.empty()) {
            res = (char)(result.top() + 'a') + res;
            result.pop();
        }
        return res;
    }
};