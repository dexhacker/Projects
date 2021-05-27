//
// Created by dexhacker on 5/22/21.
//

#ifndef LEETCODE_SYMMETRIC_TREE_H
#define LEETCODE_SYMMETRIC_TREE_H

#include "../TreeNode.h"
#include <iostream>

using namespace std;

namespace symmetric_tree {
    class Solution {
    public:
        bool isSymmetric(TreeNode* root);
        void test();
    };
}

#endif //LEETCODE_SYMMETRIC_TREE_H
