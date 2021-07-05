//
// Created by dexhacker on 6/21/21.
//

#ifndef LEETCODE_SWIM_IN_RISING_WATER_H
#define LEETCODE_SWIM_IN_RISING_WATER_H

#include <iostream>
#include <vector>

using namespace std;

namespace swim_in_rising_water {
    class Solution {
    public:
        struct T {
            int t, x, y;
            T(int a, int b, int c) : t (a), x (b), y (c) {}
            bool operator< (const T &d) const {return t > d.t;}
        };

        int swimInWater(vector<vector<int>>& grid);
        void test();
    };
}

#endif //LEETCODE_SWIM_IN_RISING_WATER_H
