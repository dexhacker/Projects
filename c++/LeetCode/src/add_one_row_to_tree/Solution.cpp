//
// Created by dexhacker on 10/5/22.
//

#include "Solution.h"
#include <cassert>

TreeNode *add_one_row_to_tree::Solution::addOneRow(TreeNode *root, int val, int depth) {
    if (depth == 1) {
        auto node = new TreeNode(val);
        node->left = root;
        return node;
    }

    if (depth == 2) {
        auto node1 = new TreeNode(val);
        node1->left = root->left;
        root->left = node1;

        auto node2 = new TreeNode(val);
        node2->right = root->right;
        root->right = node2;

        return root;
    }

    if (root->left) addOneRow(root->left, val, depth - 1);
    if (root->right) addOneRow(root->right, val, depth - 1);

    return root;
}

void add_one_row_to_tree::Solution::test() {
    auto node1 = new TreeNode(4);
    auto node2 = new TreeNode(2);
    auto node3 = new TreeNode(3);
    auto node4 = new TreeNode(1);
    node1->left = node2;
    node2->left = node3;
    node2->right = node4;
    auto answer = addOneRow(node1, 1, 3);
    assert(answer->left->left->val == 1);
    assert(answer->left->right->val == 1);

    cout << "addOneRow completed!" << endl;
}
