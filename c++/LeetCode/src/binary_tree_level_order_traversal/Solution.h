//
// Created by dexhacker on 5/26/21.
//

#ifndef LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace binary_tree_level_order_traversal {
    class Solution {
    public:
        void dfs(TreeNode* root, int index);
        vector<vector<int>> levelOrder(TreeNode* root);
        void test();

    private:
        vector<vector<int>> answer;
    };
}

#endif //LEETCODE_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
