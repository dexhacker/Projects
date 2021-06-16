//
// Created by dexhacker on 6/14/21.
//

#ifndef LEETCODE_MAXIMUM_UNITS_ON_A_TRUCK_H
#define LEETCODE_MAXIMUM_UNITS_ON_A_TRUCK_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_units_on_a_truck {
    class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_UNITS_ON_A_TRUCK_H
