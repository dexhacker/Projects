//
// Created by dexhacker on 5/24/21.
//

#ifndef LEETCODE_MAXIMUM_DEPTH_OF_N_ARY_TREE_H
#define LEETCODE_MAXIMUM_DEPTH_OF_N_ARY_TREE_H

#include "../Node.h"
#include <iostream>

using namespace std;

namespace maximum_depth_of_n_ary_tree {
    class Solution {
    public:
        int maxDepth(Node* root);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_DEPTH_OF_N_ARY_TREE_H
