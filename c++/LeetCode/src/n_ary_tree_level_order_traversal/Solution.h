//
// Created by dexhacker on 8/6/21.
//

#ifndef LEETCODE_N_ARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define LEETCODE_N_ARY_TREE_LEVEL_ORDER_TRAVERSAL_H

#include <iostream>
#include <vector>
#include "../Node.h"

using namespace std;

namespace n_ary_tree_level_order_traversal {
    class Solution {
    public:
        vector<vector<int>> levelOrder(Node* root);
        void test();
    };
}

#endif //LEETCODE_N_ARY_TREE_LEVEL_ORDER_TRAVERSAL_H
