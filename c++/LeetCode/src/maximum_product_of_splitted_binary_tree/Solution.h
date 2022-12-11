//
// Created by dexhacker on 12/11/22.
//

#ifndef LEETCODE_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H
#define LEETCODE_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../TreeNode.h"

using namespace std;

namespace maximum_product_of_splitted_binary_tree {
    class Solution {
    public:
        void sum_dfs(TreeNode* node);
        void dfs(TreeNode* node);
        int maxProduct(TreeNode* root);
        void test();

    private:
        unordered_map<TreeNode*, long> m;
        vector<long> variants;
        long root_sum = 0;
    };
}

#endif //LEETCODE_MAXIMUM_PRODUCT_OF_SPLITTED_BINARY_TREE_H
