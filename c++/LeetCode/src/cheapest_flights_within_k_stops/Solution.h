//
// Created by dexhacker on 1/26/23.
//

#ifndef LEETCODE_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H
#define LEETCODE_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H

#include <iostream>
#include <vector>

using namespace std;

namespace cheapest_flights_within_k_stops {
    class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k);
        void test();
    };
}

#endif //LEETCODE_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H
