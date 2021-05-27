//
// Created by dexhacker on 5/24/21.
//

#include "Solution.h"
#include <cassert>

Node * populating_next_right_pointers_in_each_node::Solution::connect(Node *root, Node *parent) {
    if (root == nullptr) return nullptr;

    if (parent != nullptr) {
        if (parent->left == root) {
            root->next = parent->right;
        } else {
            if (parent->next != nullptr) root->next = parent->next->left;
        }
    }

    connect(root->right, root);
    connect(root->left, root);

    return root;
}

void populating_next_right_pointers_in_each_node::Solution::test() {
    auto t1_n1 = new Node(1);
    auto t1_n2 = new Node(2);
    auto t1_n3 = new Node(3);
    auto t1_n4 = new Node(4);
    auto t1_n5 = new Node(5);
    auto t1_n6 = new Node(6);
    auto t1_n7 = new Node(7);
    t1_n1->left = t1_n2;
    t1_n1->right = t1_n3;
    t1_n2->left = t1_n4;
    t1_n2->right = t1_n5;
    t1_n3->left = t1_n6;
    t1_n3->right = t1_n7;
    assert(connect(t1_n1) == t1_n1);

    cout << "connect completed!" << endl;
}
