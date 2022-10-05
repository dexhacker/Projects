//
// Created by dexhacker on 10/5/22.
//

#ifndef LEETCODE_ADD_ONE_ROW_TO_TREE_H
#define LEETCODE_ADD_ONE_ROW_TO_TREE_H

#include <iostream>
#include "../TreeNode.h"

using namespace std;

namespace add_one_row_to_tree {
    class Solution {
    public:
        TreeNode* addOneRow(TreeNode* root, int val, int depth);
        void test();
    };
}

#endif //LEETCODE_ADD_ONE_ROW_TO_TREE_H
