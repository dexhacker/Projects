//
// Created by Фарид Абдугалыев on 14.12.2021.
//

#include "Solution.h"
#include <cassert>

void range_sum_of_bst::Solution::bst(TreeNode *node) {
    if (l <= node->val && node->val <= h) sum += node->val;
    if (node->left) bst(node->left);
    if (node->right) bst(node->right);
}

int range_sum_of_bst::Solution::rangeSumBST(TreeNode *root, int low, int high) {
    sum = 0;
    l = low;
    h = high;

    bst(root);

    return sum;
}

void range_sum_of_bst::Solution::test() {
    auto t1 = new TreeNode(10);
    auto t2 = new TreeNode(5);
    auto t3 = new TreeNode(15);
    auto t4 = new TreeNode(3);
    auto t5 = new TreeNode(7);
    auto t6 = new TreeNode(18);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->right = t6;

    assert(rangeSumBST(t1, 7, 15) == 32);

    cout << "rangeSumBST completed!" << endl;
}
