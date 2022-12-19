//
// Created by dexhacker on 12/19/22.
//

#ifndef LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
#define LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_if_path_exists_in_graph {
    class Solution {
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination);
        void test();
    };
}

#endif //LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
