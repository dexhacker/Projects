//
// Created by dexhacker on 9/30/22.
//

#ifndef LEETCODE_THE_SKYLINE_PROBLEM_H
#define LEETCODE_THE_SKYLINE_PROBLEM_H

#include <iostream>
#include <vector>

using namespace std;

namespace the_skyline_problem {
    class Solution {
    public:
        vector<vector<int>> getSkyline(vector<vector<int>>& buildings);
        void test();
    };
}

#endif //LEETCODE_THE_SKYLINE_PROBLEM_H
