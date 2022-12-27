//
// Created by dexhacker on 12/27/22.
//

#ifndef LEETCODE_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H
#define LEETCODE_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_bags_with_full_capacity_of_rocks {
    class Solution {
    public:
        int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H
