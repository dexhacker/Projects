//
// Created by dexhacker on 7/24/21.
//

#ifndef LEETCODE_BINARY_TREE_PRUNING_H
#define LEETCODE_BINARY_TREE_PRUNING_H

#include <iostream>
#include "../TreeNode.h"

using namespace std;

namespace binary_tree_pruning {
    class Solution {
    public:
        bool dfs(TreeNode* root);
        TreeNode* pruneTree(TreeNode* root);
        void test();
    };
}

#endif //LEETCODE_BINARY_TREE_PRUNING_H
