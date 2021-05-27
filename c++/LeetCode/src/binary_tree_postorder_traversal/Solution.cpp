//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

void binary_tree_postorder_traversal::Solution::dfs(TreeNode *root) {
    if (root == nullptr) return;
    if (root->left != nullptr) postorderTraversal(root->left);
    if (root->right != nullptr) postorderTraversal(root->right);
    answer.push_back(root->val);
}

vector<int> binary_tree_postorder_traversal::Solution::postorderTraversal(TreeNode *root) {
    dfs(root);
    return answer;
}

void binary_tree_postorder_traversal::Solution::test() {
    auto t1_tn1 = new TreeNode(1);
    auto t1_tn2 = new TreeNode(2);
    auto t1_tn3 = new TreeNode(3);
    t1_tn1->right = t1_tn2;
    t1_tn2->left = t1_tn3;
    vector<int> answer1 {3, 2, 1};
    assert(postorderTraversal(t1_tn1) == answer1);

    cout << "postorderTraversal completed!" << endl;
}
