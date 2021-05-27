//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_PATH_WITH_MAXIMUM_PROBABILITY_H
#define LEETCODE_PATH_WITH_MAXIMUM_PROBABILITY_H

#include <iostream>
#include <vector>

using namespace std;

namespace path_with_maximum_probability {
    class Solution {
    public:
        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end);
        void test();
    };
}

#endif //LEETCODE_PATH_WITH_MAXIMUM_PROBABILITY_H
