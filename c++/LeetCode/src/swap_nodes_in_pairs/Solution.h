//
// Created by dexhacker on 6/23/21.
//

#ifndef LEETCODE_SWAP_NODES_IN_PAIRS_H
#define LEETCODE_SWAP_NODES_IN_PAIRS_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

namespace swap_nodes_in_pairs {
    class Solution {
    public:
        ListNode* swapPairs(ListNode* head);
        void test();
    };
}

#endif //LEETCODE_SWAP_NODES_IN_PAIRS_H
