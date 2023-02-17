//
// Created by dexhacker on 2/17/23.
//

#ifndef LEETCODE_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H
#define LEETCODE_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H

#include <iostream>
#include <climits>
#include "../TreeNode.h"

using namespace std;

namespace minimum_distance_between_bst_nodes {
    class Solution {
    private:
        int answer = INT_MAX;

    public:
        int dfs(TreeNode* root, int i);
        int minDiffInBST(TreeNode* root);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H
