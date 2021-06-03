//
// Created by dexhacker on 6/3/21.
//

#ifndef LEETCODE_CLOSEST_DIVISORS_H
#define LEETCODE_CLOSEST_DIVISORS_H

#include <iostream>
#include <vector>

using namespace std;

namespace closest_divisors {
    class Solution {
    public:
        pair<int, int> find_divisor(int num);
        vector<int> closestDivisors(int num);
        void test();
    };
}

#endif //LEETCODE_CLOSEST_DIVISORS_H
