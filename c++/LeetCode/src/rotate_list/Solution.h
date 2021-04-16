//
// Created by dexhacker on 4/15/21.
//

#ifndef LEETCODE_ROTATE_LIST_H
#define LEETCODE_ROTATE_LIST_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace rotate_list {
    class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k);
        void test();
    };
}

#endif //LEETCODE_ROTATE_LIST_H
