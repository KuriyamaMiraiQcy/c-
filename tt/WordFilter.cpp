//
// Created by 62339 on 2023/11/17.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

class WordFilter {
    struct Trie {
        std::vector<int> indexes;
        Trie* next[26] {};
    };
public:
    WordFilter(std::vector<std::string>& words) {
        prefix = new Trie();
        suffix = new Trie();
        w = words;

        for (int i = 0; i < words.size(); ++i) {
            Trie* start = prefix;
            add(i, start);

            for (int j = 0; j < words[i].size() / 2; ++j) {
                std::swap(w[i][j], w[i][w[i].size() - 1 - j]);
            }
            start = suffix;
            add(i, start);
        }

    }

    int f(std::string pref, std::string suff) {
        Trie* start = prefix;
        for (int i = 0; i < pref.size(); ++i) {
            if (start->next[pref[i] - 'a'] == nullptr) {
                return -1;
            }
            start = start->next[pref[i] - 'a'];
        }
        auto& set_1 = start->indexes;
        start = suffix;
        for (int i = suff.size() - 1; i >= 0; --i) {
            if (start->next[suff[i] - 'a'] == nullptr) {
                return -1;
            }
            start = start->next[suff[i] - 'a'];
        }
        auto& set_2 = start->indexes;


        for (int i = set_1.size() - 1, j = set_2.size() - 1; i >= 0 && j >= 0;) {
            if (set_1[i] > set_2[j]) {
                --i;
            } else if (set_1[i] < set_2[j]) {
                --j;
            } else {
                return set_1[i];
            }
        }
        return -1;
    }
private:
    Trie* prefix;
    Trie* suffix;
    std::vector<std::string> w;

    void add(int index, Trie* start) {
        std::string str = w[index];
        start->indexes.emplace_back(index);
        for (int i = 0; i < str.size(); ++i) {
            int l = str[i] - 'a';
            if (start->next[l] == nullptr) {
                start->next[l] = new Trie();
            }
            start->next[l]->indexes.emplace_back(index);
            start = start->next[l];
        }
    }

    std::vector<int>& filter(std::string s, Trie* start) {
        std::vector<int> empty;
        for (int i = 0; i < s.size(); ++i) {
            if (start->next[s[i] - 'a'] == nullptr) {
                return empty;
            }
            start = start->next[s[i] - 'a'];
        }
        return start->indexes;
    }
};

//int main() {
//    std::vector<std::string> w = {"abbba", "abba"};
//    WordFilter a(w);
//    std::cout << a.f("ab", "ba");
//}