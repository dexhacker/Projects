//
// Created by dexhacker on 5/22/21.
//

#ifndef LEETCODE_SAME_TREE_H
#define LEETCODE_SAME_TREE_H

#include "../TreeNode.h"
#include <iostream>

using namespace std;

namespace same_tree {
    class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q);
        void test();
    };
}

#endif //LEETCODE_SAME_TREE_H
