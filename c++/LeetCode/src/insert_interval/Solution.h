//
// Created by dexhacker on 11/17/22.
//

#ifndef LEETCODE_INSERT_INTERVAL_H
#define LEETCODE_INSERT_INTERVAL_H

#include <iostream>
#include <vector>

using namespace std;

namespace insert_interval {
    class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
        void test();
    };
}

#endif //LEETCODE_INSERT_INTERVAL_H
