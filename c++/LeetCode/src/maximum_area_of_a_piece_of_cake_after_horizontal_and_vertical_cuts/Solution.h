//
// Created by dexhacker on 6/3/21.
//

#ifndef LEETCODE_MAXIMUM_AREA_OF_A_PIECE_OF_CAKE_AFTER_HORIZONTAL_AND_VERTICAL_CUTS_H
#define LEETCODE_MAXIMUM_AREA_OF_A_PIECE_OF_CAKE_AFTER_HORIZONTAL_AND_VERTICAL_CUTS_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_area_of_a_piece_of_cake_after_horizontal_and_vertical_cuts {
    class Solution {
    public:
        long max_long(long a, long b);
        int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_AREA_OF_A_PIECE_OF_CAKE_AFTER_HORIZONTAL_AND_VERTICAL_CUTS_H
