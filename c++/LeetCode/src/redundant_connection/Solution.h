//
// Created by dexhacker on 5/24/21.
//

#ifndef LEETCODE_REDUNDANT_CONNECTION_H
#define LEETCODE_REDUNDANT_CONNECTION_H

#include <iostream>
#include <vector>

using namespace std;

namespace redundant_connection {
    class Solution {
    public:
        void dfs(int v, vector<vector<int>> & adjacency_list, vector<bool> & visited);
        vector<int> findRedundantConnection(vector<vector<int>>& edges);
        void test();
    };
}

#endif //LEETCODE_REDUNDANT_CONNECTION_H
