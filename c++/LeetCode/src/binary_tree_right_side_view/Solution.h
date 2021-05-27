//
// Created by dexhacker on 3/25/21.
//

#ifndef LEETCODE_BINARY_TREE_RIGHT_SIDE_VIEW_H
#define LEETCODE_BINARY_TREE_RIGHT_SIDE_VIEW_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace binary_tree_right_side_view {
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root);
        void test();
    };
}

#endif //LEETCODE_BINARY_TREE_RIGHT_SIDE_VIEW_H
