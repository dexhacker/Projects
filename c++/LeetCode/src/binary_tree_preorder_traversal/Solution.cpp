//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

void binary_tree_preorder_traversal::Solution::dfs(TreeNode *root) {
    if (root == nullptr) return;
    answer.push_back(root->val);
    if (root->left != nullptr) preorderTraversal(root->left);
    if (root->right != nullptr) preorderTraversal(root->right);
}

vector<int> binary_tree_preorder_traversal::Solution::preorderTraversal(TreeNode *root) {
    dfs(root);
    return answer;
}

void binary_tree_preorder_traversal::Solution::test() {
    auto t1_tn1 = new TreeNode(1);
    auto t1_tn2 = new TreeNode(2);
    auto t1_tn3 = new TreeNode(3);
    t1_tn1->right = t1_tn2;
    t1_tn2->left = t1_tn3;
    vector<int> answer1 {1, 2, 3};
    assert(preorderTraversal(t1_tn1) == answer1);

    cout << "preorderTraversal completed!" << endl;
}
