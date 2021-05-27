//
// Created by dexhacker on 5/24/21.
//

#ifndef LEETCODE_CLONE_GRAPH_H
#define LEETCODE_CLONE_GRAPH_H

#include "../Node.h"
#include <iostream>
#include <unordered_map>

using namespace std;

namespace clone_graph {
    class Solution {
    public:
        Node* cloneGraph(Node* node);
        void test();

    private:
        unordered_map<Node*, Node*> hash_map;
    };
}

#endif //LEETCODE_CLONE_GRAPH_H
