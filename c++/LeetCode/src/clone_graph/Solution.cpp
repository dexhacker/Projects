//
// Created by dexhacker on 5/24/21.
//

#include "Solution.h"
#include <cassert>

Node * clone_graph::Solution::cloneGraph(Node *node) {
    if (node == nullptr) return nullptr;
    if (hash_map[node] != nullptr) return hash_map[node];

    auto node_copy = new Node(node->val);
    hash_map[node] = node_copy;
    for (auto & neighbor : node->neighbors) node_copy->neighbors.push_back(cloneGraph(neighbor));

    return node_copy;
}

void clone_graph::Solution::test() {
    auto t1_n1 = new Node(1);
    auto t1_n2 = new Node(2);
    auto t1_n3 = new Node(3);
    auto t1_n4 = new Node(4);
    t1_n1->neighbors = {t1_n2, t1_n4};
    t1_n2->neighbors = {t1_n1, t1_n3};
    t1_n3->neighbors = {t1_n2, t1_n4};
    t1_n4->neighbors = {t1_n1, t1_n3};
    assert(cloneGraph(t1_n1) != t1_n1);

    assert(cloneGraph(nullptr) == nullptr);

    cout << "cloneGraph completed!" << endl;
}
