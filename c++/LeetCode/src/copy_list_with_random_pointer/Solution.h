//
// Created by dexhacker on 4/16/21.
//

#ifndef LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
#define LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H

#include "../Node.h"
#include <iostream>

using namespace std;

namespace copy_list_with_random_pointer {
    class Solution {
    public:
        Node* copyRandomList(Node* head);
        void test();
    };
}

#endif //LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
