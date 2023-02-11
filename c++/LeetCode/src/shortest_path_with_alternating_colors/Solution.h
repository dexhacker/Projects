//
// Created by dexhacker on 2/11/23.
//

#ifndef LEETCODE_SHORTEST_PATH_WITH_ALTERNATING_COLORS_H
#define LEETCODE_SHORTEST_PATH_WITH_ALTERNATING_COLORS_H

#include <iostream>
#include <vector>

using namespace std;

namespace shortest_path_with_alternating_colors {
    class Solution {
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges);
        void test();
    };
}

#endif //LEETCODE_SHORTEST_PATH_WITH_ALTERNATING_COLORS_H
