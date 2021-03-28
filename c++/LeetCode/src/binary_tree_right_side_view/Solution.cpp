//
// Created by dexhacker on 3/25/21.
//

#include "Solution.h"
#include <cassert>

void fill_matrix_by_node(vector<vector<int>> &matrix, int index, TreeNode *node) {
    if (matrix.size() < index + 1) {
        vector<int> temp = {node->val};
        matrix.push_back(temp);
    } else {
        matrix[index].push_back(node->val);
    }
    if (node->left) fill_matrix_by_node(matrix, index + 1, node->left);
    if (node->right) fill_matrix_by_node(matrix, index + 1, node->right);
}

vector<int> binary_tree_right_side_view::Solution::rightSideView(TreeNode *root) {
    vector<int> answer;
    vector<vector<int>> matrix;

    if (root) fill_matrix_by_node(matrix, 0, root);

    for (int i = 0; i < matrix.size(); i++) {
        answer.push_back(matrix[i][matrix[i].size() - 1]);
    }
    return answer;
}

void binary_tree_right_side_view::Solution::test() {
    auto * test1_node5 = new TreeNode(5);
    auto * test1_node4 = new TreeNode(4);
    auto * test1_node3 = new TreeNode(3);
    auto * test1_node2 = new TreeNode(2);
    auto * test1_node1 = new TreeNode(1);
    test1_node2->right = test1_node5;
    test1_node3->right = test1_node4;
    test1_node1->left = test1_node2;
    test1_node1->right = test1_node3;
    vector<int> answer1 = {1, 3, 4};
    assert(rightSideView(test1_node1) == answer1);

    auto * test2_node3 = new TreeNode(3);
    auto * test2_node1 = new TreeNode(1);
    test2_node1->right = test2_node3;
    vector<int> answer2 = {1, 3};
    assert(rightSideView(test2_node1) == answer2);

    vector<int> answer3;
    assert(rightSideView(nullptr) == answer3);

    auto * test4_node2 = new TreeNode(2);
    auto * test4_node1 = new TreeNode(1);
    test4_node1->left = test4_node2;
    vector<int> answer4 = {1, 2};
    assert(rightSideView(test4_node1) == answer4);

    auto * test5_node4 = new TreeNode(4);
    auto * test5_node3 = new TreeNode(3);
    auto * test5_node2 = new TreeNode(2);
    auto * test5_node1 = new TreeNode(1);
    test5_node2->left = test5_node4;
    test5_node1->left = test5_node2;
    test5_node1->right = test5_node3;
    vector<int> answer5 = {1, 3, 4};
    assert(rightSideView(test5_node1) == answer5);

    cout << "rightSideView completed!" << endl;
}
