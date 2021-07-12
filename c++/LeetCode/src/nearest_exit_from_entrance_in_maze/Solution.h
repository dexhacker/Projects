//
// Created by dexhacker on 7/12/21.
//

#ifndef LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H
#define LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H

#include <iostream>
#include <vector>

using namespace std;

namespace nearest_exit_from_entrance_in_maze {
    class Solution {
    public:
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance);
        void test();
    };
}

#endif //LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H
