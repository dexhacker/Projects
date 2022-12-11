//
// Created by dexhacker on 12/11/22.
//

#ifndef LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
#define LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H

#include <iostream>
#include <vector>
#include "../TreeNode.h"

using namespace std;

namespace binary_tree_maximum_path_sum {
    class Solution {
    public:
        int dfs(TreeNode* node);
        int maxPathSum(TreeNode* root);
        void test();

    private:
        vector<int> variants;
    };
}

#endif //LEETCODE_BINARY_TREE_MAXIMUM_PATH_SUM_H
