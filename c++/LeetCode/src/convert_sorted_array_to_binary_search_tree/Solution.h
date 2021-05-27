//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
#define LEETCODE_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace convert_sorted_array_to_binary_search_tree {
    class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums);
        void test();
    };
}

#endif //LEETCODE_CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_H
