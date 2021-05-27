//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
#define LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace construct_binary_tree_from_inorder_and_postorder_traversal {
    class Solution {
    public:
        void find_left(TreeNode *root, int index, int start_pos, int finish_pos);
        void find_right(TreeNode *root, int index, int start_pos, int finish_pos);
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
        void test();

    private:
        vector<int> po, io;
    };
}

#endif //LEETCODE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H
