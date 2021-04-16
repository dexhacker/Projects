//
// Created by dexhacker on 4/15/21.
//

#ifndef LEETCODE_LINKED_LIST_CYCLE_H
#define LEETCODE_LINKED_LIST_CYCLE_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace linked_list_cycle {
    class Solution {
    public:
        bool hasCycle(ListNode *head);
        void test();
    };
}

#endif //LEETCODE_LINKED_LIST_CYCLE_H
