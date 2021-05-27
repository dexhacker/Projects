//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

void binary_tree_inorder_traversal::Solution::dfs(TreeNode *root) {
    if (root == nullptr) return;
    if (root->left != nullptr) inorderTraversal(root->left);
    answer.push_back(root->val);
    if (root->right != nullptr) inorderTraversal(root->right);
}

vector<int> binary_tree_inorder_traversal::Solution::inorderTraversal(TreeNode *root) {
    dfs(root);
    return answer;
}

void binary_tree_inorder_traversal::Solution::test() {
    auto t1_tn1 = new TreeNode(1);
    auto t1_tn2 = new TreeNode(2);
    auto t1_tn3 = new TreeNode(3);
    t1_tn1->right = t1_tn2;
    t1_tn2->left = t1_tn3;
    vector<int> answer1 {1, 3, 2};
    assert(inorderTraversal(t1_tn1) == answer1);

    cout << "inorderTraversal completed!" << endl;
}
