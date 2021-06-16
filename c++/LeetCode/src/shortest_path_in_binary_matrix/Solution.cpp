//
// Created by dexhacker on 3/26/21.
//

#include "Solution.h"
#include <cassert>
#include <queue>
#include <map>

int shortest_path_in_binary_matrix::Solution::shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    queue<pair<int, int>> points;
    map<pair<int, int>, int> hash_map;
    points.push(make_pair(0, 0));
    hash_map[make_pair(0, 0)] = 1;
    while (!points.empty()) {
        auto current_point = points.front();
        if (grid[current_point.first][current_point.second] == 1) {
            return -1;
        }
        int x_start = (current_point.first - 1 < 0) ? 0 : current_point.first - 1;
        int y_start = (current_point.second - 1 < 0) ? 0 : current_point.second - 1;
        int x_finish = (current_point.first + 1 < grid.size()) ? current_point.first + 1 : grid.size() - 1;
        int y_finish = (current_point.second + 1 < grid.size()) ? current_point.second + 1 : grid.size() - 1;
        for (int i = x_finish; i >= x_start; i--) {
            for (int j = y_finish; j >= y_start; j--) {
                if (current_point.first == i && current_point.second == j) continue;
                if (grid[i][j] == 1) continue;
                auto current_pair = make_pair(i, j);
                if (hash_map.count(current_pair) > 0) continue;
                points.push(current_pair);
                hash_map[current_pair] = hash_map[current_point] + 1;
            }
        }
        points.pop();
    }
    return (hash_map.count(make_pair(grid.size() - 1, grid[grid.size() - 1].size() - 1)) > 0) ? hash_map[make_pair(grid.size() - 1, grid[grid.size() - 1].size() - 1)] : -1;
}

void shortest_path_in_binary_matrix::Solution::test() {
    vector<vector<int>> test1 {{0, 1}, {1, 0}};
    assert(shortestPathBinaryMatrix(test1) == 2);

    vector<vector<int>> test2 {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    assert(shortestPathBinaryMatrix(test2) == 4);

    vector<vector<int>> test3 {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    assert(shortestPathBinaryMatrix(test3) == -1);

    vector<vector<int>> test4 {
        {0, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 0}
    };
    assert(shortestPathBinaryMatrix(test4) == 14);

    vector<vector<int>> test5 {
        {0, 1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0}
    };
    assert(shortestPathBinaryMatrix(test5) == 7);

    vector<vector<int>> test6{
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 0}
    };
    assert(shortestPathBinaryMatrix(test6) == 14);

    cout << "shortestPathBinaryMatrix completed!" << endl;
};
