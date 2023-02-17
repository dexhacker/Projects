//
// Created by dexhacker on 2/17/23.
//

#ifndef LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H
#define LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H

#include <iostream>
#include <climits>
#include "../TreeNode.h"

using namespace std;

namespace minimum_absolute_difference_in_bst {
    class Solution {
    private:
        int answer = INT_MAX;

    public:
        int dfs(TreeNode* root, int i);
        int getMinimumDifference(TreeNode* root);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H
