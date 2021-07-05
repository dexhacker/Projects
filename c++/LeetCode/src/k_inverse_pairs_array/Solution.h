//
// Created by dexhacker on 6/19/21.
//

#ifndef LEETCODE_K_INVERSE_PAIRS_ARRAY_H
#define LEETCODE_K_INVERSE_PAIRS_ARRAY_H

#include <iostream>

using namespace std;

namespace k_inverse_pairs_array {
    class Solution {
    public:
        int kInversePairs(int n, int k);
        void test();

    private:
        const int MOD = 1e9+7;
    };
}

#endif //LEETCODE_K_INVERSE_PAIRS_ARRAY_H
