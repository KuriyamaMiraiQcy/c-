//
// Created by 62339 on 2023/11/27.
//
#include <string>
#include <vector>
class reorganize_string {
public:
    std::string reorganizeString(std::string s) {
        std::vector<int> count(26);
        std::string result(s);
        for (auto& ch:s) {
            count[ch - 'a']++;
            if (count[ch - 'a'] > (int)(s.size() + 1) / 2) {
                return "";
            }
        }
        int first = 0, second = 1;
        for (int i = 0; i < count.size(); ++i) {
            while (count[i] > 0 && count[i] <= s.size() / 2 && second < s.size()) {
                result[second] = (char)('a' + i);
                count[i]--;
                second += 2;
            }
            while (count[i] > 0 && first < s.size()) {
                result[first] = (char)('a' + i);
                first += 2;
                count[i]--;
            }
        }
        return result;
    }
};