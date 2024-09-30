//
// Created by 62339 on 2023/10/18.
//
#include "Robot.cpp"
#include <set>
#include <functional>

class robot_room_cleaner {
public:
    void cleanRoom(Robot &robot) {
        auto go_back = [&]() -> void {
            robot.turnLeft();
            robot.turnLeft();
            robot.move();
            robot.turnLeft();
            robot.turnLeft();
        };
        std::set<std::pair<int, int>> visited;
        int x = 0, y = 0;

        std::function<void(int, int, int)> dfs = [&](int x, int y, int direction) -> void {
            visited.emplace(x, y);
            robot.clean();

            for (int i = 0; i < 4; ++i) {
                int n_dir = (direction + i) % 4;
                if (visited.find(std::pair<int, int>(x + directions[n_dir][0], y + directions[n_dir][1])) ==
                    visited.end() && robot.move()) {
                    dfs(x + directions[n_dir][0], y + directions[n_dir][1], n_dir);
                    go_back();
                }
                robot.turnLeft();
            }

        };
        dfs(0, 0, 0);
    }

private:
    int directions[4][2] = {{0,  1},
                            {-1, 0},
                            {0,  -1},
                            {1,  0}};
};