//
// Created by dexhacker on 7/8/21.
//

#ifndef LEETCODE_KTH_SMALLEST_ELEMENT_IN_A_SORTED_MATRIX_H
#define LEETCODE_KTH_SMALLEST_ELEMENT_IN_A_SORTED_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

namespace kth_smallest_element_in_a_sorted_matrix {
    class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k);
        void test();
    };
}

#endif //LEETCODE_KTH_SMALLEST_ELEMENT_IN_A_SORTED_MATRIX_H
