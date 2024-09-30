//
// Created by 62339 on 2023/10/16.
//
#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

class tesla {
    int solution(std::vector<int> &A) {
        // Implement your solution here
        std::vector<int> bit_count(32, 0);
        for (int num: A) {
            int bit = 31;
            while (num != 0) {
                if ((num & 1) == 1) {
                    bit_count[bit]++;
                }
                num = num >> 1;
                --bit;
            }
        }

        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result = std::max(result, bit_count[i]);
        }
        return result;
    }

    int dfs(std::string &S, int cur, std::vector<int> &memo, std::vector<std::vector<int>> &adj,
            std::unordered_set<int> &visited) {
        if (adj[cur].empty()) {
            memo[cur] = 1;
        }
        if (memo[cur] != -1) {
            return memo[cur];
        }
        int result = 0;
        visited.emplace(cur);
        for (int adj_node: adj[cur]) {
            if (S[adj_node] != S[cur] && visited.find(adj_node) == visited.end()) {
                result = std::max(result, dfs(S, adj_node, memo, adj, visited));
            }
        }
        memo[cur] = result + 1;
        return result + 1;
    }

    bool solution2(std::vector<int> &A, std::vector<int> &B, int S) {
        // Implement your solution here
        return dfs2(A, B, 0, std::unordered_set<int>());
    }

    bool dfs2(std::vector<int> &A, std::vector<int> &B, int cur, std::unordered_set<int> used) {
        if (cur == A.size()) {
            return true;
        }
        bool result = false;
        if (used.find(A[cur]) == used.end()) {
            used.emplace(A[cur]);
            result |= dfs2(A, B, cur + 1, used);
            used.erase(A[cur]);
        }
        if (used.find(B[cur]) == used.end()) {
            used.emplace(B[cur]);
            result |= dfs2(A, B, cur + 1, used);
            used.erase(A[cur]);
        }
        return result;
    }

public:
    int solution1(std::string &S, std::vector<int> &A) {
        // Implement your solution here
        int n = S.size();
        std::vector<std::vector<int>> adj(n, std::vector<int>());

        for (int i = 1; i < n; ++i) {
            adj[A[i]].emplace_back(i);
        }
        dfs(0, adj, S);
        return result + 1;
    }

    int result = 0;

    int dfs(int cur, std::vector<std::vector<int>> &adj, std::string &s) {
        int max_length = 0;
        for (int adj_node: adj[cur]) {
            int length = dfs(adj_node, adj, s) + 1;
            if (s[adj_node] != s[cur]) {
                result = std::max(result, max_length + length);
                max_length = std::max(max_length, length);
            }
        }
        return max_length;
    }
};

//int main() {
//    tesla a;
//
//    std::string b = "abbab";
//    std::vector<int> c({-1, 0, 0,0,2});
//    std::cout<< a.solution1(b, c);
//}