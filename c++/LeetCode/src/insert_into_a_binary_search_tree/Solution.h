//
// Created by Фарид Абдугалыев on 12.01.2022.
//

#ifndef LEETCODE_INSERT_INTO_A_BINARY_SEARCH_TREE_H
#define LEETCODE_INSERT_INTO_A_BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>
#include "../TreeNode.h"

using namespace std;

namespace insert_into_a_binary_search_tree {
    class Solution {
    public:
        void fillVector(TreeNode* root, int val);
        TreeNode* toTreeNode(int l, int r);
        TreeNode* insertIntoBST(TreeNode* root, int val);
        void test();

    private:
        vector<int> numbers;
        bool isAdd = false;
    };
}

#endif //LEETCODE_INSERT_INTO_A_BINARY_SEARCH_TREE_H
