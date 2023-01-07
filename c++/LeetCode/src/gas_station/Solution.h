//
// Created by dexhacker on 1/7/23.
//

#ifndef LEETCODE_GAS_STATION_H
#define LEETCODE_GAS_STATION_H

#include <iostream>
#include <vector>

using namespace std;

namespace gas_station {
    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
        void test();
    };
}

#endif //LEETCODE_GAS_STATION_H
