//
// Created by dexhacker on 7/12/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int nearest_exit_from_entrance_in_maze::Solution::nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<vector<int>, int>> q;
    maze[entrance[0]][entrance[1]] = '+';
    q.push({entrance, 0});
    while (!q.empty()) {
        auto current_pair = q.front();
        q.pop();
        if (current_pair.first[0] - 1 < 0 and current_pair.second > 0) return current_pair.second;
        if (current_pair.first[0] + 1 >= maze.size() and current_pair.second > 0) return current_pair.second;
        if (current_pair.first[1] - 1 < 0 and current_pair.second > 0) return current_pair.second;
        if (current_pair.first[1] + 1 >= maze[0].size() and current_pair.second > 0) return current_pair.second;

        if (current_pair.first[0] - 1 >= 0 and maze[current_pair.first[0] - 1][current_pair.first[1]] == '.') {
            maze[current_pair.first[0] - 1][current_pair.first[1]] = '+';
            q.push({{current_pair.first[0] - 1, current_pair.first[1]}, current_pair.second + 1});
        }

        if (current_pair.first[0] + 1 < maze.size() and maze[current_pair.first[0] + 1][current_pair.first[1]] == '.') {
            maze[current_pair.first[0] + 1][current_pair.first[1]] = '+';
            q.push({{current_pair.first[0] + 1, current_pair.first[1]}, current_pair.second + 1});
        }

        if (current_pair.first[1] - 1 >= 0 and maze[current_pair.first[0]][current_pair.first[1] - 1] == '.') {
            maze[current_pair.first[0]][current_pair.first[1] - 1] = '+';
            q.push({{current_pair.first[0], current_pair.first[1] - 1}, current_pair.second + 1});
        }

        if (current_pair.first[1] + 1 < maze[0].size() and maze[current_pair.first[0]][current_pair.first[1] + 1] == '.') {
            maze[current_pair.first[0]][current_pair.first[1] + 1] = '+';
            q.push({{current_pair.first[0], current_pair.first[1] + 1}, current_pair.second + 1});
        }
    }

    return -1;
}

void nearest_exit_from_entrance_in_maze::Solution::test() {
    vector<vector<char>> maze {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance {1, 2};
    assert(nearestExit(maze, entrance) == 1);

    cout << "nearestExit completed!" << endl;
}
