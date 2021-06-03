//
// Created by dexhacker on 6/2/21.
//

#ifndef LEETCODE_POWX_N_H
#define LEETCODE_POWX_N_H

#include <iostream>
#include <unordered_map>

using namespace std;

namespace powx_n {
    class Solution {
    public:
        double myPowAbs(double x, long n);
        double myPow(double x, int n);
        void test();

    private:
        unordered_map<int, double> hm;
    };
}

#endif //LEETCODE_POWX_N_H
