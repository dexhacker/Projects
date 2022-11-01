//
// Created by dexhacker on 11/1/22.
//

#include "Solution.h"
#include <cassert>

vector<int> where_will_the_ball_fall::Solution::findBall(vector<vector<int>> &grid) {
    vector<int> balls;
    for (int i = 0; i < grid[0].size(); i++) balls.push_back(i);

    for (auto row : grid) {
        vector<int> new_balls;
        for (auto j : balls) {
            if (j == -1) {
                new_balls.push_back(-1);
                continue;
            }

            if (row[j] == 1 && j + 1 < row.size() && row[j + 1] == 1) {
                new_balls.push_back(j + 1);
                continue;
            }

            if (row[j] == -1 && j - 1 >= 0 && row[j - 1] == -1) {
                new_balls.push_back(j - 1);
                continue;
            }

            new_balls.push_back(-1);
        }
        balls = new_balls;
    }

    return balls;
}

void where_will_the_ball_fall::Solution::test() {
    vector<vector<int>> test {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    vector<int> answer {1, -1, -1, -1, -1};
    assert(findBall(test) == answer);

    cout << "findBall completed!" << endl;
}
