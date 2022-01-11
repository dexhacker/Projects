//
// Created by Фарид Абдугалыев on 11.01.2022.
//

#include "Solution.h"
#include <cmath>
#include <cassert>

void sum_of_root_to_leaf_binary_numbers::Solution::dfs(TreeNode *root, string str_number) {
    if (root->left && root->right) {
        dfs(root->left, str_number + to_string(root->val));
        dfs(root->right, str_number + to_string(root->val));
    } else if (root->left) {
        dfs(root->left, str_number + to_string(root->val));
    } else if (root->right) {
        dfs(root->right, str_number + to_string(root->val));
    } else {
        str_number += to_string(root->val);
        int length = str_number.size();
        int number = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (str_number[i] == '1') number += pow(2, length - 1 - i);
        }
        answer += number;
    }
}

int sum_of_root_to_leaf_binary_numbers::Solution::sumRootToLeaf(TreeNode *root) {
    dfs(root, "");

    return answer;
}

void sum_of_root_to_leaf_binary_numbers::Solution::test() {
    auto tn1 = new TreeNode(1);
    auto tn2 = new TreeNode(0);
    auto tn3 = new TreeNode(1);
    auto tn4 = new TreeNode(0);
    auto tn5 = new TreeNode(1);
    auto tn6 = new TreeNode(0);
    auto tn7 = new TreeNode(1);
    tn1->left = tn2;
    tn1->right = tn3;
    tn2->left = tn4;
    tn2->right = tn5;
    tn3->left = tn6;
    tn3->right = tn7;

    assert(sumRootToLeaf(tn1) == 22);

    cout << "sumRootToLeaf completed!" << endl;
}
