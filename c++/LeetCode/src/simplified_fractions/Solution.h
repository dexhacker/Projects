//
// Created by dexhacker on 6/3/21.
//

#ifndef LEETCODE_SIMPLIFIED_FRACTIONS_H
#define LEETCODE_SIMPLIFIED_FRACTIONS_H

#include <iostream>
#include <vector>

using namespace std;

namespace simplified_fractions {
    class Solution {
    public:
        int gcd(int a, int b);
        vector<string> simplifiedFractions(int n);
        void test();
    };
}

#endif //LEETCODE_SIMPLIFIED_FRACTIONS_H
