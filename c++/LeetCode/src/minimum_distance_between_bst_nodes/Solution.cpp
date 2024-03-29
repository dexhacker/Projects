//
// Created by dexhacker on 2/17/23.
//

#include "Solution.h"
#include <cassert>

int minimum_distance_between_bst_nodes::Solution::dfs(TreeNode *root, int i) {
    if (root->left) i = dfs(root->left, i);

    if (i != -1) answer = min(answer, root->val - i);
    i = root->val;

    if (root->right) i = dfs(root->right, i);
    return i;
}

int minimum_distance_between_bst_nodes::Solution::minDiffInBST(TreeNode *root) {
    dfs(root, -1);
    return answer;
}

void minimum_distance_between_bst_nodes::Solution::test() {
    auto n1 = new TreeNode(4);
    auto n2 = new TreeNode(2);
    auto n3 = new TreeNode(1);
    auto n4 = new TreeNode(3);
    auto n5 = new TreeNode(6);
    n2->left = n3;
    n2->right = n4;
    n1->left = n2;
    n1->right = n5;
    assert(minDiffInBST(n1) == 1);

    cout << "minDiffInBST completed!" << endl;
}
