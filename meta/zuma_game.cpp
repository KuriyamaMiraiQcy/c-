//
// Created by 62339 on 2023/10/28.
//
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;
class zuma_game {
    int ans, used;
    unordered_map<char, int> rem;
    stack<pair<char, int>> st;

    // inserted 表示在当前位置与前一个位置同色的情况下，两个位置之间是否插入过异色球
    void dfs(int pos, string &board, bool inserted) {
        if (used >= ans)
            return;

        if (pos == board.size()) {
            if (st.empty())
                ans = used;
            return;
        }

        // 将pos位置的小球加入
        if (!st.empty() && st.top().first == board[pos]) {
            st.top().second++;
        } else {
            st.emplace(board[pos], 1);
        }

        // 1. 不额外插入小球的情形
        // 1.1 当前颜色满三个，且后面没有相同颜色的球
        if (st.top().second >= 3 && (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
            auto tmp = st.top();
            st.pop();
            dfs(pos + 1, board, false);
            st.push(tmp);
        }

        // 1.2. 当前颜色小球不满三个
        // 1.3. 当前颜色小球恰好三个，但当前小球和上一小球不同色，或者之前插入过非同色球，这说明初始情形为XX...X，之后中间的小球被消去，从而形成了XXX，这种情况是允许的。因为我们可改变消去的顺序。如果当前小球和上一小球同色，则说明初始情形为X...XX，此时假设右边还有X，则中间的XX要么结合左边的X，要么结合右边的X，不可能同时结合。如果当前小球数量已经达到四个，则不可能再积累更多同色球，因为最多只可能形成四连珠，五连珠在形成前至少有一边已经达到三个，是不可能形成的。
        if (st.top().second < 3 ||
            (st.top().second == 3 && (board[pos] != board[pos - 1] || inserted)))
            dfs(pos + 1, board, false);

        // 2. 插入与当前位置同色的小球
        if (rem[board[pos]] >= 1 &&
            (pos + 1 == board.size() || board[pos + 1] != board[pos])) {
            int lim = rem[board[pos]];
            for (int i = 1; i <= min(2, lim); ++i) { // 至多插入两个
                // 加入i个同色小球
                rem[board[pos]] -= i;
                used += i;
                st.top().second += i;
                if (st.top().second >= 3) { // 累积同色球达到三个
                    auto tmp = st.top();      // 维护现场
                    st.pop();                 // 消去同色球
                    dfs(pos + 1, board, false);
                    st.push(tmp); // 还原现场
                } else {
                    dfs(pos + 1, board, false);
                }

                // 还原现场
                st.top().second -= i;
                used -= i;
                rem[board[pos]] += i;
            }
        }

        // 3. 当后面有相同颜色的球时，尝试插入与当前位置不同色的小球
        if (pos + 1 < board.size() && board[pos + 1] == board[pos]) {
            auto tmp = st.top(); // 维护现场
            if (tmp.second >= 3) // 消去当前积累的同色小球
                st.pop();

            for (auto[ch, num]: rem) {
                if (ch == board[pos] || num == 0)
                    continue;
                int hi = (tmp.second >= 3) ? min(3, num) : 1; // 如果当前小球积累不足三个，则至多只插入一个分隔
                for (int j = 1; j <= min(3, num); ++j) {
                    rem[ch] -= j;
                    used += j;

                    // 加入j个小球
                    if (!st.empty() && st.top().first == ch) {
                        st.top().second += j;
                    } else {
                        st.emplace(ch, j);
                    }

                    if (st.top().second >= 3) { // 插入的异色球和之前的球累加达到了三个
                        auto tmp2 = st.top(); // 维护现场
                        st.pop();             // 消去同色球
                        dfs(pos + 1, board, true);
                        st.push(tmp2); // 还原现场
                    } else {
                        dfs(pos + 1, board, true);
                    }

                    // 还原现场
                    if (st.top().second > j) {
                        st.top().second -= j;
                    } else {
                        st.pop();
                    }
                    used -= j;
                    rem[ch] += j;
                }
            }

            if (tmp.second >= 3)
                st.push(tmp); // 还原现场
        }

        // 还原现场
        if (st.top().second == 1) {
            st.pop();
        } else {
            st.top().second--;
        }
    }

public:
    int findMinStep(string board, string hand) {
        for (char ch: hand)
            rem[ch]++;

        ans = 1e9;
        used = 0;
        dfs(0, board, false);
        return ans == 1e9 ? -1 : ans;
    }
};