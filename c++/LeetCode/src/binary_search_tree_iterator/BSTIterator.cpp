//
// Created by dexhacker on 5/27/21.
//

#include "BSTIterator.h"
#include <cassert>

void binary_search_tree_iterator::BSTIterator::dfs(TreeNode *root) {
    if (root == nullptr) return;
    if (root->left != nullptr) dfs(root->left);
    numbers.push_back(root->val);
    if (root->right != nullptr) dfs(root->right);
}

binary_search_tree_iterator::BSTIterator::BSTIterator(TreeNode *root) {
    dfs(root);
    counter = 0;
}

int binary_search_tree_iterator::BSTIterator::next() {
    counter++;
    return numbers[counter - 1];
}

bool binary_search_tree_iterator::BSTIterator::hasNext() {
    return (counter < numbers.size());
}

void binary_search_tree_iterator::BSTIterator::test() {
    auto tree_node1 = new TreeNode(7);
    auto tree_node2 = new TreeNode(3);
    auto tree_node3 = new TreeNode(15);
    auto tree_node4 = new TreeNode(9);
    auto tree_node5 = new TreeNode(20);
    tree_node1->left = tree_node2;
    tree_node1->right = tree_node3;
    tree_node3->left = tree_node4;
    tree_node3->right = tree_node5;
    auto it = new BSTIterator(tree_node1);
    assert(it->next() == 3);
    assert(it->next() == 7);
    assert(it->hasNext() == true);
    assert(it->next() == 9);
    assert(it->hasNext() == true);
    assert(it->next() == 15);
    assert(it->hasNext() == true);
    assert(it->next() == 20);
    assert(it->hasNext() == false);

    cout << "BSTIterator completed!" << endl;
}
