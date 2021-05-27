//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H
#define LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H

#include "../TreeNode.h"
#include <iostream>

using namespace std;

namespace validate_binary_search_tree {
    class Solution {
    public:
        bool isValidBST(TreeNode* root, long min = INT64_MIN, long max = INT64_MAX);
        void test();
    };
}

#endif //LEETCODE_VALIDATE_BINARY_SEARCH_TREE_H
