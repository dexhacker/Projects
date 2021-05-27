//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace binary_tree_preorder_traversal {
    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root);
        void dfs(TreeNode* root);
        void test();

    private:
        vector<int> answer;
    };
}

#endif //LEETCODE_BINARY_TREE_PREORDER_TRAVERSAL_H
