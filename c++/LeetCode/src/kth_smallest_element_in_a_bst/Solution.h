//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_KTH_SMALLEST_ELEMENT_IN_A_BST_H
#define LEETCODE_KTH_SMALLEST_ELEMENT_IN_A_BST_H

#include "../TreeNode.h"
#include <iostream>

using namespace std;

namespace kth_smallest_element_in_a_bst {
    class Solution {
    public:
        void dfs(TreeNode* root);
        int kthSmallest(TreeNode* root, int k);
        void test();

    private:
        int count, answer;
    };
}

#endif //LEETCODE_KTH_SMALLEST_ELEMENT_IN_A_BST_H
