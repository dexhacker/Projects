//
// Created by dexhacker on 6/3/21.
//

#ifndef LEETCODE_FOUR_DIVISORS_H
#define LEETCODE_FOUR_DIVISORS_H

#include <iostream>
#include <vector>

using namespace std;

namespace four_divisors {
    class Solution {
    public:
        vector<int> find_divisors(int number);
        int sumFourDivisors(vector<int>& nums);
        void test();
    };
}

#endif //LEETCODE_FOUR_DIVISORS_H
