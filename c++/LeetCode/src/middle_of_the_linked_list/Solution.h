//
// Created by Фарид Абдугалыев on 28.12.2021.
//

#ifndef LEETCODE_MIDDLE_OF_THE_LINKED_LIST_H
#define LEETCODE_MIDDLE_OF_THE_LINKED_LIST_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

namespace middle_of_the_linked_list {
    class Solution {
    public:
        ListNode* middleNode(ListNode* head);
        void test();
    };
}

#endif //LEETCODE_MIDDLE_OF_THE_LINKED_LIST_H
