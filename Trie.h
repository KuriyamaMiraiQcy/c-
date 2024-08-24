//
// Created by 62339 on 2023/9/23.
//

#ifndef C___TRIE_H
#define C___TRIE_H

#include <string>
#include <vector>

class Trie {
    struct TreeNode {
        char ch;
        std::vector<TreeNode *> next;
        bool is_word;

        explicit TreeNode(char _ch) : ch{_ch}, is_word{false} {
            next = std::vector<TreeNode *>();
        };
    };

private:
    TreeNode *head;
public:
    Trie() {
        head = new TreeNode('\0');
    }

    void insert(std::string word) {
        TreeNode *cur = head;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next[word[i] - 'a'] == nullptr) {
                cur->next[word[i] - 'a'] = new TreeNode(word[i]);
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur->is_word = true;
    }

    bool search(std::string word) {
        TreeNode *cur = head;
        for (int i = 0; i < word.size(); ++i) {
            if (cur->next[word[i] - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[word[i] - 'a'];
        }
        return cur->is_word;
    }

    bool startsWith(std::string prefix) {
        TreeNode *cur = head;
        for (int i = 0; i < prefix.size(); ++i) {
            if (cur->next[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            cur = cur->next[prefix[i] - 'a'];
        }
        return true;
    }
};


#endif //C___TRIE_H
