//
// Created by dexhacker on 12/8/22.
//

#ifndef LEETCODE_LEAF_SIMILAR_TREES_H
#define LEETCODE_LEAF_SIMILAR_TREES_H

#include <iostream>
#include <vector>
#include "../TreeNode.h"

using namespace std;

namespace leaf_similar_trees {
    class Solution {
    public:
        void dfs(TreeNode* root, vector<int>& leaf);
        bool leafSimilar(TreeNode* root1, TreeNode* root2);
        void test();
    };
}

#endif //LEETCODE_LEAF_SIMILAR_TREES_H
