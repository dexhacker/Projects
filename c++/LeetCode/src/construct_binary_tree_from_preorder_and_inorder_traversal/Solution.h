//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H
#define LEETCODE_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace construct_binary_tree_from_preorder_and_inorder_traversal {
    class Solution {
    public:
        void find_left(TreeNode *root, int index, int start_pos, int finish_pos);
        void find_right(TreeNode *root, int index, int start_pos, int finish_pos);
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
        void test();

    private:
        vector<int> po, io;
    };
}

#endif //LEETCODE_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H
