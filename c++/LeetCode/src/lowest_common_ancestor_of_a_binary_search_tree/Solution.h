//
// Created by dexhacker on 7/19/21.
//

#ifndef LEETCODE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H
#define LEETCODE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H

#include <iostream>
#include <unordered_map>
#include "../TreeNode.h"

using namespace std;

namespace lowest_common_ancestor_of_a_binary_search_tree {
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
        void saveParents(TreeNode* root, TreeNode* parent);
        void test();

    private:
        unordered_map<TreeNode*, TreeNode*> parents;
    };
}

#endif //LEETCODE_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H
