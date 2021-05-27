//
// Created by dexhacker on 5/24/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int maximum_depth_of_n_ary_tree::Solution::maxDepth(Node *root) {
    if (root == nullptr) return 0;
    if (root->children.empty()) return 1;
    int maxPath = 0;
    for (auto & child : root->children) maxPath = max(maxPath, maxDepth(child));
    return 1 + maxPath;
}

void maximum_depth_of_n_ary_tree::Solution::test() {
    auto t1_n1 = new Node(1);
    auto t1_n2 = new Node(2);
    auto t1_n3 = new Node(3);
    auto t1_n4 = new Node(4);
    auto t1_n5 = new Node(5);
    auto t1_n6 = new Node(6);
    t1_n1->children = {t1_n2, t1_n3, t1_n4};
    t1_n3->children = {t1_n5, t1_n6};
    assert(maxDepth(t1_n1) == 3);

    auto t2_n1 = new Node(1);
    auto t2_n2 = new Node(2);
    auto t2_n3 = new Node(3);
    auto t2_n4 = new Node(4);
    auto t2_n5 = new Node(5);
    auto t2_n6 = new Node(6);
    auto t2_n7 = new Node(7);
    auto t2_n8 = new Node(8);
    auto t2_n9 = new Node(9);
    auto t2_n10 = new Node(10);
    auto t2_n11 = new Node(11);
    auto t2_n12 = new Node(12);
    auto t2_n13 = new Node(13);
    auto t2_n14 = new Node(14);
    t2_n1->children = {t2_n2, t2_n3, t2_n4, t2_n5};
    t2_n3->children = {t2_n6, t2_n7};
    t2_n4->children = {t2_n8};
    t2_n5->children = {t2_n9, t2_n10};
    t2_n7->children = {t2_n11};
    t2_n8->children = {t2_n12};
    t2_n9->children = {t2_n13};
    t2_n11->children = {t2_n14};
    assert(maxDepth(t2_n1) == 5);

    cout << "maxDepth completed!" << endl;
}
