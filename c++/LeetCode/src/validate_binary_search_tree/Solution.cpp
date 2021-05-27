//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

bool validate_binary_search_tree::Solution::isValidBST(TreeNode *root, long min, long max) {
    if (root == nullptr) return false;
    if (root->val <= min or root->val >= max) return false;
    if (root->left != nullptr and !isValidBST(root->left, min, root->val)) return false;
    if (root->right != nullptr and !isValidBST(root->right, root->val, max)) return false;
    return true;
}

void validate_binary_search_tree::Solution::test() {
    auto t1_tn1 = new TreeNode(1);
    auto t1_tn2 = new TreeNode(2);
    auto t1_tn3 = new TreeNode(3);
    t1_tn2->left = t1_tn1;
    t1_tn2->right = t1_tn3;
    assert(isValidBST(t1_tn2) == true);

    auto t2_tn1 = new TreeNode(1);
    auto t2_tn3 = new TreeNode(3);
    auto t2_tn4 = new TreeNode(4);
    auto t2_tn5 = new TreeNode(5);
    auto t2_tn6 = new TreeNode(6);
    t2_tn5->left = t2_tn1;
    t2_tn5->right = t2_tn4;
    t2_tn4->left = t2_tn3;
    t2_tn4->right = t2_tn6;
    assert(isValidBST(t2_tn5) == false);

    cout << "isValidBST completed!" << endl;
}
