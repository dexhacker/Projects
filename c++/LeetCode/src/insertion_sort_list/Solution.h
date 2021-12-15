//
// Created by Фарид Абдугалыев on 15.12.2021.
//

#ifndef LEETCODE_INSERTION_SORT_LIST_H
#define LEETCODE_INSERTION_SORT_LIST_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

namespace insertion_sort_list {
    class Solution {
    public:
        ListNode* insertionSortList(ListNode* head);
        void test();
    };
}

#endif //LEETCODE_INSERTION_SORT_LIST_H
