//
// Created by dexhacker on 5/22/21.
//

#ifndef LEETCODE_PATH_SUM_H
#define LEETCODE_PATH_SUM_H

#include "../TreeNode.h"
#include <iostream>

using namespace std;

namespace path_sum {
    class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum);
        void test();
    };
}

#endif //LEETCODE_PATH_SUM_HH
