//
// Created by dexhacker on 3/17/21.
//

#ifndef LEETCODE_MERGE_INTERVALS_H
#define LEETCODE_MERGE_INTERVALS_H

#include <iostream>
#include <vector>

using namespace std;

namespace merge_intervals {
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals);
        void test();
    };
}

#endif //LEETCODE_MERGE_INTERVALS_H
