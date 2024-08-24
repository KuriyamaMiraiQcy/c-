#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <unordered_map>


const int directions[4][2] = {{0,  1},
                              {0,  -1},
                              {1,  0},
                              {-1, 0}};

int unique_string(std::string str) {
    if (str.size() < 3) {
        return 0;
    }
    std::string init = str.substr(0, 3);
    std::unordered_set<std::string> set;
    set.insert(init);
    for (int i = 3; i < str.size(); i++) {
        init.erase(0, 1);
        init += str.at(i);
        set.insert(init);
    }
    return set.size();
}

void print_space(int count) {
    for (int i = 0; i < count; i++) {
        std::cout << ' ';
    }
}

void pyramid(std::string str) {
    if (str.length() <= 1) {
        std::cout << str;
    }
    int level = floor(sqrt(str.length()));
    if (str.length() > level * level) {
        level++;
    }
    int line_length = 2 * level - 1;
    for (int i = 0; i < level - 1; i++) {
        int space = (line_length - 2 * i - 1) / 2;
        print_space(space);
        for (int j = i * i; j < (i + 1) * (i + 1) && j < str.length(); j++) {
            std::cout << str[j];
        }
        print_space(space);
        std::cout << '\n';
    }
    for (int i = pow(level - 1, 2); i < str.length(); i++) {
        std::cout << str[i];
    }
}

std::unordered_map<int, std::unordered_map<std::string, int>> map;

int pos(int x, int y, int n) {
    return x * n + y;
}

std::string convert(std::set<int> *visited) {
    std::string result;
    for (int n: *visited) {
        result += std::to_string(n) + '|';
    }
    return result;
}

int find_next(int x, int y, int steps, int n, std::set<int> *visited) {
    int result = 0;
    if (steps == 0) {
        return 1;
    }
    visited->insert(pos(x, y, n));
    for (int i = 0; i < 4; i++) {
        if (x + directions[i][0] >= 0 && x + directions[i][0] <= n && y + directions[i][1] >= 0 &&
            y + directions[i][1] <= n) {
            int index = pos(x + directions[i][0], y + directions[i][1], n);
            if (visited->contains(index)) {
                continue;
            }
            std::string visit_str = convert(visited);
            if (map.contains(index) && map[index].contains(visit_str)) {
                result += map[index][visit_str];
            } else {
                result += find_next(x + directions[i][0], y + directions[i][1], steps - 1, n, visited);
            }
        }
    }
    visited->erase(pos(x, y, n));
    map[pos(x, y, n)][convert(visited)] = result;
    return result;
}

int steps(int n) {
    std::set<int> visited;
    visited.insert(0);
    return find_next(1, 0, n - 1, n, &visited);
}

//int main() {
//    std::cout << unique_string("sdfrf") << '\n';
//    pyramid("sdfrf78564huihjkfvmfhgjfjhfjhf");
//    std::cout << '\n';
//    std::cout << steps(17);
//}