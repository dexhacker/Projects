//
// Created by dexhacker on 12/23/22.
//

#ifndef LEETCODE_SUM_OF_DISTANCES_IN_TREE_H
#define LEETCODE_SUM_OF_DISTANCES_IN_TREE_H

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

namespace sum_of_distances_in_tree {
    class Solution {
    private:
        vector<unordered_set<int>> tree;
        vector<int> res, count;

    public:
        vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges);
        void dfs(int root, int pre);
        void dfs2(int root, int pre);
        void test();
    };
}

#endif //LEETCODE_SUM_OF_DISTANCES_IN_TREE_H
