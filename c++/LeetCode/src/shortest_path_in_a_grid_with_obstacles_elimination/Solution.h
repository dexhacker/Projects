//
// Created by dexhacker on 10/31/22.
//

#ifndef LEETCODE_SHORTEST_PATH_IN_A_GRID_WITH_OBSTACLES_ELIMINATION_H
#define LEETCODE_SHORTEST_PATH_IN_A_GRID_WITH_OBSTACLES_ELIMINATION_H

#include <iostream>
#include <vector>

using namespace std;

namespace shortest_path_in_a_grid_with_obstacles_elimination {
    class Solution {
    public:
        int shortestPath(vector<vector<int>>& grid, int k);
        void test();
    };
}

#endif //LEETCODE_SHORTEST_PATH_IN_A_GRID_WITH_OBSTACLES_ELIMINATION_H
