//
// Created by dexhacker on 6/13/21.
//

#ifndef LEETCODE_MINIMUM_NUMBER_OF_REFUELING_STOPS_H
#define LEETCODE_MINIMUM_NUMBER_OF_REFUELING_STOPS_H

#include <iostream>
#include <vector>

using namespace std;

namespace minimum_number_of_refueling_stops {
    class Solution {
    public:
        int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_NUMBER_OF_REFUELING_STOPS_H
