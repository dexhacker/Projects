//
// Created by dexhacker on 5/23/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int number_of_islands::Solution::numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                count++;
                queue<pair<int, int>> path;
                grid[i][j] = '2';
                path.push({i, j});
                while (!path.empty()) {
                    auto current_pair = path.front();
                    path.pop();
                    if (current_pair.first - 1 >= 0 and grid[current_pair.first - 1][current_pair.second] == '1') {
                        path.push({current_pair.first - 1, current_pair.second});
                        grid[current_pair.first - 1][current_pair.second] = '2';
                    }
                    if (current_pair.second - 1 >= 0 and grid[current_pair.first][current_pair.second - 1] == '1') {
                        path.push({current_pair.first, current_pair.second - 1});
                        grid[current_pair.first][current_pair.second - 1] = '2';
                    }
                    if (current_pair.first + 1 < grid.size() and grid[current_pair.first + 1][current_pair.second] == '1') {
                        path.push({current_pair.first + 1, current_pair.second});
                        grid[current_pair.first + 1][current_pair.second] = '2';
                    }
                    if (current_pair.second + 1 < grid[0].size() and grid[current_pair.first][current_pair.second + 1] == '1') {
                        path.push({current_pair.first, current_pair.second + 1});
                        grid[current_pair.first][current_pair.second + 1] = '2';
                    }
                }
            }
        }
    }
    return count;
}

void number_of_islands::Solution::test() {
    vector<vector<char>> test1 {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };
    assert(numIslands(test1) == 1);

    vector<vector<char>> test2 {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    assert(numIslands(test2) == 3);

    vector<vector<char>> test3 {
            {'1', '1', '1'},
            {'0', '1', '0'},
            {'1', '1', '1'}
    };
    assert(numIslands(test3) == 1);

    cout << "numIslands completed!" << endl;
}