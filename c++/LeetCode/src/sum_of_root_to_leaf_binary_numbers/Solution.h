//
// Created by Фарид Абдугалыев on 11.01.2022.
//

#ifndef LEETCODE_SUM_OF_ROOT_TO_LEAF_BINARY_NUMBERS_H
#define LEETCODE_SUM_OF_ROOT_TO_LEAF_BINARY_NUMBERS_H

#include <iostream>
#include "../TreeNode.h"

using namespace std;

namespace sum_of_root_to_leaf_binary_numbers {
    class Solution {
    public:
        void dfs(TreeNode* root, string str_number);
        int sumRootToLeaf(TreeNode* root);
        void test();

    private:
        int answer = 0;
    };
}

#endif //LEETCODE_SUM_OF_ROOT_TO_LEAF_BINARY_NUMBERS_H
