//
// Created by dexhacker on 12/8/22.
//

#include "Solution.h"
#include <cassert>

void leaf_similar_trees::Solution::dfs(TreeNode *root, vector<int> &leaf) {
    if (root->left == nullptr && root->right == nullptr) {
        leaf.push_back(root->val);
        return;
    }

    if (root->left != nullptr) dfs(root->left, leaf);
    if (root->right != nullptr) dfs(root->right, leaf);
}

bool leaf_similar_trees::Solution::leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> leaf1;
    vector<int> leaf2;

    dfs(root1, leaf1);
    dfs(root2, leaf2);

    if (leaf1.size() != leaf2.size()) return false;

    for (int i = 0; i < leaf1.size(); i++) if (leaf1[i] != leaf2[i]) return false;

    return true;
}

void leaf_similar_trees::Solution::test() {
    auto node1_1 = new TreeNode(5);
    auto node1_2 = new TreeNode(6);
    auto node1_3 = new TreeNode(2);
    auto node1_4 = new TreeNode(7);
    auto node1_5 = new TreeNode(4);
    node1_1->left = node1_2;
    node1_1->right = node1_3;
    node1_3->left = node1_4;
    node1_3->right = node1_5;

    auto node2_1 = new TreeNode(1);
    auto node2_2 = new TreeNode(9);
    auto node2_3 = new TreeNode(8);
    node2_1->left = node2_2;
    node2_1->right = node2_3;

    assert(leafSimilar(node1_1, node2_1) == false);

    cout << "leafSimilar completed!" << endl;
}
