//
// Created by dexhacker on 3/25/21.
//

#ifndef LEETCODE_BINARY_TREE_RIGHT_SIDE_VIEW_H
#define LEETCODE_BINARY_TREE_RIGHT_SIDE_VIEW_H

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace binary_tree_right_side_view {
    class Solution {
    public:
        vector<int> rightSideView(TreeNode* root);
        void test();
    };
}

#endif //LEETCODE_BINARY_TREE_RIGHT_SIDE_VIEW_H
