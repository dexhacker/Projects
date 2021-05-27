//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace binary_tree_inorder_traversal {
    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root);
        void dfs(TreeNode* root);
        void test();

    private:
        vector<int> answer;
    };
}

#endif //LEETCODE_BINARY_TREE_INORDER_TRAVERSAL_H
