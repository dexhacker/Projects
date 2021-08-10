//
// Created by dexhacker on 8/6/21.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> n_ary_tree_level_order_traversal::Solution::levelOrder(Node *root) {
    vector<vector<int>> answer;
    if (root == nullptr) return answer;

    vector<Node*> nodes { root };
    while (!nodes.empty()) {
        vector<Node*> new_nodes;
        vector<int> row;
        for (auto n : nodes) {
            row.push_back(n->val);
            new_nodes.insert(new_nodes.end(), n->children.begin(), n->children.end());
        }
        answer.push_back(row);
        nodes = new_nodes;
    }
    return answer;
}

void n_ary_tree_level_order_traversal::Solution::test() {
    auto ln1 = new Node(1);
    auto ln2 = new Node(3);
    auto ln3 = new Node(2);
    auto ln4 = new Node(4);
    auto ln5 = new Node(5);
    auto ln6 = new Node(6);
    ln1->children.push_back(ln2);
    ln1->children.push_back(ln3);
    ln1->children.push_back(ln4);
    ln2->children.push_back(ln5);
    ln2->children.push_back(ln6);
    vector<vector<int>> answer {{1}, {3, 2, 4}, {5, 6}};
    assert(levelOrder(ln1) == answer);

    cout << "levelOrder completed!" << endl;
}
