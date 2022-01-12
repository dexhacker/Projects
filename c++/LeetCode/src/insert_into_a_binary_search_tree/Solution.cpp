//
// Created by Фарид Абдугалыев on 12.01.2022.
//

#include "Solution.h"
#include <cassert>

void insert_into_a_binary_search_tree::Solution::fillVector(TreeNode *root, int val) {
    if (root->left) fillVector(root->left, val);
    if (!isAdd && root->val > val) {
        isAdd = true;
        numbers.push_back(val);
    }
    numbers.push_back(root->val);
    if (root->right) fillVector(root->right, val);
}

TreeNode *insert_into_a_binary_search_tree::Solution::toTreeNode(int l, int r) {
    int index = (r - l + 1) / 2 + l;
    auto root = new TreeNode(numbers[index]);

    if (index - 1 >= l) root->left = toTreeNode(l, index - 1);
    if (index + 1 <= r) root->right = toTreeNode(index + 1, r);

    return root;
}

TreeNode *insert_into_a_binary_search_tree::Solution::insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) return new TreeNode(val);

    fillVector(root, val);
    if (!isAdd) numbers.push_back(val);
    return toTreeNode(0, numbers.size() - 1);
}

void insert_into_a_binary_search_tree::Solution::test() {
    auto tn1 = new TreeNode(4);
    auto tn2 = new TreeNode(2);
    auto tn3 = new TreeNode(7);
    auto tn4 = new TreeNode(1);
    auto tn5 = new TreeNode(3);
    tn1->left = tn2;
    tn1->right = tn3;
    tn2->left = tn4;
    tn2->right = tn5;
    auto result = insertIntoBST(tn1, 5);
    assert(result->right->left->val == 5);

    cout << "insertIntoBST completed!" << endl;
}
