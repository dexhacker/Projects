//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_SMALLEST_SUBTREE_WITH_ALL_THE_DEEPEST_NODES_H
#define LEETCODE_SMALLEST_SUBTREE_WITH_ALL_THE_DEEPEST_NODES_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace smallest_subtree_with_all_the_deepest_nodes {
    class Solution {
    public:
        void dfs(TreeNode* root, int deep, TreeNode* parent);
        TreeNode* subtreeWithAllDeepest(TreeNode* root);
        void test();

    private:
        int max_deep = 0;
        vector<TreeNode*> deeps;
        unordered_map<TreeNode*, TreeNode*> hash_map;
    };
}

#endif //LEETCODE_SMALLEST_SUBTREE_WITH_ALL_THE_DEEPEST_NODES_H
