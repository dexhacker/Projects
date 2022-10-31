//
// Created by dexhacker on 10/31/22.
//

#ifndef LEETCODE_EARLIEST_POSSIBLE_DAY_OF_FULL_BLOOM_H
#define LEETCODE_EARLIEST_POSSIBLE_DAY_OF_FULL_BLOOM_H

#include <iostream>
#include <vector>

using namespace std;

namespace earliest_possible_day_of_full_bloom {
    class Solution {
    public:
        int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime);
        void test();
    };
}

#endif //LEETCODE_EARLIEST_POSSIBLE_DAY_OF_FULL_BLOOM_H
