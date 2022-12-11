//
// Created by dexhacker on 12/11/22.
//

#include "Solution.h"
#include "cassert"

void maximum_product_of_splitted_binary_tree::Solution::sum_dfs(TreeNode *node) {
    long left = 0, right = 0;
    if (node->left) {
        sum_dfs(node->left);
        left = m[node->left];
    }
    if (node->right) {
        sum_dfs(node->right);
        right = m[node->right];
    }
    m[node] = node->val + left + right;
}

void maximum_product_of_splitted_binary_tree::Solution::dfs(TreeNode *node) {
    long left_sum = 0, right_sum = 0, left = 0, right = 0;
    if (node->left) left_sum = m[node->left];
    if (node->right) right_sum = m[node->right];
    left = left_sum * (root_sum - left_sum);
    right = right_sum * (root_sum - right_sum);
    long maximum = (left > right) ? left : right;
    variants.push_back(maximum);

    if (node->left) dfs(node->left);
    if (node->right) dfs(node->right);
}

int maximum_product_of_splitted_binary_tree::Solution::maxProduct(TreeNode *root) {
    sum_dfs(root);
    root_sum = m[root];
    dfs(root);

    long maximum = 0;
    for (auto i : variants) if (i > maximum) maximum = i;
    return maximum % 1000000007;
}

void maximum_product_of_splitted_binary_tree::Solution::test() {
    auto node1 = new TreeNode(1);
    auto node2 = new TreeNode(2);
    auto node3 = new TreeNode(3);
    auto node4 = new TreeNode(4);
    auto node5 = new TreeNode(5);
    auto node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;

    assert(maxProduct(node1) == 110);

    cout << "maxProduct completed!" << endl;
}
