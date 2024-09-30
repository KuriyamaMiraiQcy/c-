//
// Created by 62339 on 2023/11/28.
//
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>

class word_search_ii {
public:
    struct Trie {
        std::vector<Trie*> next;
        bool is_end;
        std::string s;

        Trie() {
            next = std::vector<Trie*>(26);
        }
    };
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        head = new Trie();
        for (auto& word:words) {
            add(word);
        }

        std::unordered_set<std::string> result;
        std::vector<std::vector<int>> visited(board.size(), std::vector<int>(board[0].size(), 0));

        auto is_valid = [&](int x, int y) -> bool {
            return x >= 0 && y >= 0 && x < board.size() && y < board[x].size() && !visited[x][y];
        };

        std::function<void(int, int, Trie*)> dfs = [&](int x, int y, Trie* root) {
            if (root->next[board[x][y] - 'a'] == nullptr) {
                return;
            }
            if (root->next[board[x][y] - 'a']->is_end) {
                result.emplace(root->next[board[x][y] - 'a']->s);
            }

            for (auto& dir:dirs) {
                if (is_valid(x + dir[0], y + dir[1])) {
                    visited[x + dir[0]][y + dir[1]] = 1;
                    dfs(x + dir[0], y + dir[1], root->next[board[x][y] - 'a']);
                    visited[x + dir[0]][y + dir[1]] = 0;
                }
            }
        };

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                visited[i][j] = 1;
                dfs(i, j, head);
                visited[i][j] = 0;
            }
        }
        std::vector<std::string> res;
        for (auto& s:result) {
            res.emplace_back(s);
        }
        return res;
    }

private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    Trie* head;

    void add(std::string& word) {
        Trie* h = head;
        for (auto& ch:word) {
            if (h->next[ch - 'a'] == nullptr) {
                h->next[ch - 'a'] = new Trie();
            }
            h = h->next[ch - 'a'];
        }
        h->is_end = true;
        h->s = word;
    }
};