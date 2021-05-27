//
// Created by dexhacker on 5/24/21.
//

#ifndef LEETCODE_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H
#define LEETCODE_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H

#include "../Node.h"
#include <iostream>

using namespace std;

namespace populating_next_right_pointers_in_each_node {
    class Solution {
    public:
        Node* connect(Node* root, Node* parent = nullptr);
        void test();
    };
}

#endif //LEETCODE_POPULATING_NEXT_RIGHT_POINTERS_IN_EACH_NODE_H
