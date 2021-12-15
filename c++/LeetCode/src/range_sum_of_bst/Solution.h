//
// Created by Фарид Абдугалыев on 14.12.2021.
//

#ifndef LEETCODE_RANGE_SUM_OF_BST_H
#define LEETCODE_RANGE_SUM_OF_BST_H

#include <iostream>
#include "../TreeNode.h"

using namespace std;

namespace range_sum_of_bst {
    class Solution {
    public:
        void bst(TreeNode* root);
        int rangeSumBST(TreeNode* root, int low, int high);
        void test();

    private:
        int sum, l, h;
    };
}

#endif //LEETCODE_RANGE_SUM_OF_BST_H
