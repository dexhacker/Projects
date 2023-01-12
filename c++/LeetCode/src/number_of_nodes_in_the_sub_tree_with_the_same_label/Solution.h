//
// Created by dexhacker on 1/12/23.
//

#ifndef LEETCODE_NUMBER_OF_NODES_IN_THE_SUB_TREE_WITH_THE_SAME_LABEL_H
#define LEETCODE_NUMBER_OF_NODES_IN_THE_SUB_TREE_WITH_THE_SAME_LABEL_H

#include <iostream>
#include <vector>

using namespace std;

namespace number_of_nodes_in_the_sub_tree_with_the_same_label {
    class Solution {
    public:
        vector<int> dfs(vector<vector<int>>& adj, string& labels, int i, vector<int>& result);
        vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels);
        void test();
    };
}

#endif //LEETCODE_NUMBER_OF_NODES_IN_THE_SUB_TREE_WITH_THE_SAME_LABEL_H
