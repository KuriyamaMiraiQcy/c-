//
// Created by 62339 on 2023/10/14.
//
#include <string>
#include <stack>
#include <iostream>

class basic_calculator_ii {
public:
    int calculate(std::string s) {
        s += '+';
        char oper = '+';
        int num = 0;
        std::stack<int> n;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                continue;
            }
            if (oper == '*' || oper == '/') {
                int result = oper == '*' ? n.top() * num : n.top() / num;
                n.pop();
                n.push(result);
            } else {
                n.push(oper == '+' ? num : -num);
            }
            oper = s[i];
            num = 0;
        }

        int result = 0;
        while (!n.empty()) {
            result += n.top();
            n.pop();
        }

        return result;
    }
};

int main() {
    basic_calculator_ii a;
    std::cout << a.calculate("1*9");
    return 0;
}