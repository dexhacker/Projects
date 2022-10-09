//
// Created by Фарид Абдугалыев on 09.10.2022.
//

#include "Solution.h"
#include <cassert>

bool two_sum_iv_input_is_a_bst::Solution::dfs(TreeNode *root, int k, unordered_map<int, bool> &m) {
    if (m.count(root->val) > 0) return true;

    m[k - root->val] = true;

    if (root->left && dfs(root->left, k, m)) return true;
    if (root->right && dfs(root->right, k, m)) return true;

    return false;
}

bool two_sum_iv_input_is_a_bst::Solution::findTarget(TreeNode *root, int k) {
    unordered_map<int, bool> m;
    return dfs(root, k, m);
}

void two_sum_iv_input_is_a_bst::Solution::test() {
    auto node1 = new TreeNode(5);
    auto node2 = new TreeNode(3);
    auto node3 = new TreeNode(6);
    auto node4 = new TreeNode(2);
    auto node5 = new TreeNode(4);
    auto node6 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    assert(findTarget(node1, 9) == true);

    cout << "findTarget completed!" << endl;
}
