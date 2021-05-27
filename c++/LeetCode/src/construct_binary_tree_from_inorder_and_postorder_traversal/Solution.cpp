//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

void construct_binary_tree_from_inorder_and_postorder_traversal::Solution::find_left(TreeNode *root, int index,
                                                                                     int start_pos, int finish_pos) {
    for (int j = index; j >= 0; j--) {
        for (int i = start_pos; i <= finish_pos; i++) {
            if (io[i] == po[j]) {
                auto temp = new TreeNode(po[j]);
                root->left = temp;
                find_right(temp, j - 1, i + 1, finish_pos);
                find_left(temp, j - 1, start_pos, i - 1);
                return;
            }
        }
    }
}

void construct_binary_tree_from_inorder_and_postorder_traversal::Solution::find_right(TreeNode *root, int index,
                                                                                      int start_pos, int finish_pos) {
    for (int j = index; j >= 0; j--) {
        for (int i = start_pos; i <= finish_pos; i++) {
            if (io[i] == po[j]) {
                auto temp = new TreeNode(po[j]);
                root->right = temp;
                find_right(temp, j - 1, i + 1, finish_pos);
                find_left(temp, j - 1, start_pos, i - 1);
                return;
            }
        }
    }
}

TreeNode * construct_binary_tree_from_inorder_and_postorder_traversal::Solution::buildTree(vector<int> &inorder,
                                                                                           vector<int> &postorder) {
    po = postorder, io = inorder;

    auto root = new TreeNode(postorder[postorder.size() - 1]);
    for (int i = 0; i < inorder.size(); i++) {
        if (root->val == inorder[i]) {
            find_right(root, postorder.size() - 2, i + 1, inorder.size() - 1);
            find_left(root, postorder.size() - 2, 0, i - 1);
        }
    }

    return root;
}

void construct_binary_tree_from_inorder_and_postorder_traversal::Solution::test() {
    vector<int> test1_io {9, 3, 15, 20, 7};
    vector<int> test1_po {9, 15, 7, 20, 3};
    assert(buildTree(test1_io, test1_po)->val == 3);

    cout << "buildTree completed!" << endl;
}
