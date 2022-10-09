//
// Created by Фарид Абдугалыев on 09.10.2022.
//

#ifndef LEETCODE_TWO_SUM_IV_INPUT_IS_A_BST_H
#define LEETCODE_TWO_SUM_IV_INPUT_IS_A_BST_H

#include <iostream>
#include <unordered_map>
#include "../TreeNode.h"

using namespace std;

namespace two_sum_iv_input_is_a_bst {
    class Solution {
    public:
        bool dfs(TreeNode* root, int k, unordered_map<int, bool> & m);
        bool findTarget(TreeNode* root, int k);
        void test();
    };
}

#endif //LEETCODE_TWO_SUM_IV_INPUT_IS_A_BST_H
