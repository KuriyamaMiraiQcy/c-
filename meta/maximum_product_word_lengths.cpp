//
// Created by 62339 on 2023/11/6.
//
#include <vector>
#include <string>
class maximum_product_word_lengths {
public:
    int maxProduct(std::vector<std::string>& words) {
        std::vector<int> masks(words.size());

        for (int i = 0; i < words.size(); ++i) {
            masks[i] = convert(words[i]);
        }

        int result = 0;
        for (int i = 0; i < masks.size(); ++i) {
            for (int j = i + 1; j < masks.size(); ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    result = std::max(result, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return result;
    }

private:
    int convert(std::string s) {
        int result = 0;
        for (auto& ch:s) {
            result |= 1 << (ch - 'a');
        }
        return result;
    }
};