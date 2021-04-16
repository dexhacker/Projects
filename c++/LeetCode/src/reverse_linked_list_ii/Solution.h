//
// Created by dexhacker on 4/15/21.
//

#ifndef LEETCODE_REVERSE_LINKED_LIST_II_H
#define LEETCODE_REVERSE_LINKED_LIST_II_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace reverse_linked_list_ii {
    class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right);
        void test();
    };
}

#endif //LEETCODE_REVERSE_LINKED_LIST_II_H
