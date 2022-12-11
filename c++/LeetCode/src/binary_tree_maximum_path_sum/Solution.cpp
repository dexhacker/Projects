//
// Created by dexhacker on 12/11/22.
//

#include "Solution.h"
#include <cassert>

int binary_tree_maximum_path_sum::Solution::dfs(TreeNode *node) {
    int left = 0, right = 0;
    if (node->left) left = dfs(node->left);
    if (node->right) right = dfs(node->right);
    int maximum = max(node->val, node->val + left);
    maximum = max(maximum, node->val + right);
    maximum = max(maximum, node->val + right + left);
    variants.push_back(maximum);

    int output = node->val + max(left, right);
    return max(node->val, output);
}

int binary_tree_maximum_path_sum::Solution::maxPathSum(TreeNode *root) {
    dfs(root);
    int maximum = -1001;
    for (int i : variants) if (i > maximum) maximum = i;
    return maximum;
}

void binary_tree_maximum_path_sum::Solution::test() {
    auto node1 = new TreeNode(1);
    auto node2 = new TreeNode(2);
    auto node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    assert(maxPathSum(node1) == 6);

    cout << "maxPathSum completed!" << endl;
}
