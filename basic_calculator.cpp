//
// Created by 62339 on 2023/9/6.
//
#include <string>
#include <stack>

class basic_calculator {
public:
    int calculate(std::string s) {
        std::stack<int> st;
        int ans = 0, num = 0, op = 1;
        st.push(op);

        for (char c: s) {
            if (c == ' ') continue;
            else if (c >= '0') num = num * 10 - '0' + c;
            else {
                ans += op * num;
                num = 0;

                if (c == '+') op = st.top();
                else if (c == '-') op = -st.top();
                else if (c == '(') st.push(op);
                else st.pop();
            }
        }

        return ans + op * num;
    }
};