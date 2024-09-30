//
// Created by 62339 on 2023/11/25.
//
#include <vector>
#include <string>
#include <unordered_set>
class restore_ip_addresses {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        adds = std::vector<std::string>(4);
        dfs(0, 0, s);
        return {result.begin(), result.end()};
    }
private:
    std::vector<std::string> adds;
    std::unordered_set<std::string> result;

    void dfs(int index, int count, std::string& s) {
        if (count == 4) {
            if (index == s.size()) {
                std::string ip = to_ip();
                if (result.find(ip) == result.end()) {
                    result.emplace(ip);
                }
            }
            return;
        }
        if (index == s.size()) {
            return;
        }
        if (s[index] == '0') {
            adds[count] = "0";
            dfs(index + 1, count + 1, s);
            adds[count] = "";
            return;
        }

        std::string con;
        for (int i = index; i < index + 3 && i < s.size(); ++i) {
            con += s[i];
            if (!is_valid(con)) {
                break;
            }
            adds[count] = con;
            dfs(i + 1, count + 1, s);
            adds[count] = "";
        }
    }

    bool is_valid(std::string& s) {
        return stoi(s) >= 0 && stoi(s) <= 255;
    }

    std::string to_ip() {
        std::string res;
        for (auto& add: adds) {
            res += add;
            res += ".";
        }
        res.pop_back();
        return res;
    }
};