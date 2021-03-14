//
// Created by dexhacker on 3/11/21.
//

#ifndef LEETCODE_SUPER_UGLY_NUMBER_H
#define LEETCODE_SUPER_UGLY_NUMBER_H

#include <iostream>
#include <vector>

using namespace std;

namespace super_ugly_number {
    class Solution {
    public:
        int nthSuperUglyNumber(int n, vector<int>& primes);
        void test();
    };
}


#endif //LEETCODE_SUPER_UGLY_NUMBER_H
