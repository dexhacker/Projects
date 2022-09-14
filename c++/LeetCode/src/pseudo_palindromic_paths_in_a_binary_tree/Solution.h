//
// Created by dexhacker on 9/14/22.
//

#ifndef LEETCODE_PSEUDO_PALINDROMIC_PATHS_IN_A_BINARY_TREE_H
#define LEETCODE_PSEUDO_PALINDROMIC_PATHS_IN_A_BINARY_TREE_H

#include <iostream>
#include <vector>
#include "../TreeNode.h"

using namespace std;

namespace pseudo_palindromic_paths_in_a_binary_tree {
    class Solution {
    public:
        void dfs(TreeNode* root, vector<int> counts);
        int pseudoPalindromicPaths (TreeNode* root);
        void test();

    private:
        int answer = 0;
    };
}

#endif //LEETCODE_PSEUDO_PALINDROMIC_PATHS_IN_A_BINARY_TREE_H
