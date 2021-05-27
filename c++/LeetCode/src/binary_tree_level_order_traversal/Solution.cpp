//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

void binary_tree_level_order_traversal::Solution::dfs(TreeNode *root, int index) {
    if (root == nullptr) return;

    if (answer.size() > index) {
        answer[index].push_back(root->val);
    } else {
        vector<int> temp {root->val};
        answer.push_back(temp);
    }
    if (root->left != nullptr) dfs(root->left, index + 1);
    if (root->right != nullptr) dfs(root->right, index + 1);
}

vector<vector<int>> binary_tree_level_order_traversal::Solution::levelOrder(TreeNode *root) {
    dfs(root, 0);
    return answer;
}

void binary_tree_level_order_traversal::Solution::test() {
    auto t1_tn1 = new TreeNode(3);
    auto t1_tn2 = new TreeNode(9);
    auto t1_tn3 = new TreeNode(20);
    auto t1_tn4 = new TreeNode(15);
    auto t1_tn5 = new TreeNode(7);
    t1_tn1->left = t1_tn2;
    t1_tn1->right = t1_tn3;
    t1_tn3->left = t1_tn4;
    t1_tn3->right = t1_tn5;
    vector<vector<int>> answer1 {{3}, {9, 20}, {15, 7}};
    assert(levelOrder(t1_tn1) == answer1);

    cout << "levelOrder completed!" << endl;
}
