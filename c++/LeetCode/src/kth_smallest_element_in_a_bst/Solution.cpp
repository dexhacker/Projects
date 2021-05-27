//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <cassert>

void kth_smallest_element_in_a_bst::Solution::dfs(TreeNode *root) {
    if (root == nullptr or count == 0) return;

    if (root->left != nullptr) dfs(root->left);
    count--;
    if (count == 0) {
        answer = root->val;
        return;
    }
    if (root->right != nullptr) dfs(root->right);
}

int kth_smallest_element_in_a_bst::Solution::kthSmallest(TreeNode *root, int k) {
    count = k, answer = 0;
    dfs(root);
    return answer;
}

void kth_smallest_element_in_a_bst::Solution::test() {
    auto tree_node1 = new TreeNode(1);
    auto tree_node2 = new TreeNode(2);
    auto tree_node3 = new TreeNode(3);
    auto tree_node4 = new TreeNode(4);
    auto tree_node5 = new TreeNode(5);
    auto tree_node6 = new TreeNode(6);
    tree_node5->left = tree_node3;
    tree_node5->right = tree_node6;
    tree_node3->left = tree_node2;
    tree_node3->right = tree_node4;
    tree_node2->left = tree_node1;
    assert(kthSmallest(tree_node5, 3) == 3);

    cout << "kthSmallest completed!" << endl;
}
