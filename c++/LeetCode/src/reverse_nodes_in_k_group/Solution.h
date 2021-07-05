//
// Created by dexhacker on 6/24/21.
//

#ifndef LEETCODE_REVERSE_NODES_IN_K_GROUP_H
#define LEETCODE_REVERSE_NODES_IN_K_GROUP_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

namespace reverse_nodes_in_k_group {
    class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k);
        void test();
    };
}

#endif //LEETCODE_REVERSE_NODES_IN_K_GROUP_H
