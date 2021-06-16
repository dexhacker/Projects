//
// Created by dexhacker on 6/7/21.
//

#ifndef LEETCODE_MINIMUM_SPACE_WASTED_FROM_PACKAGING_H
#define LEETCODE_MINIMUM_SPACE_WASTED_FROM_PACKAGING_H

#include <iostream>
#include <vector>

using namespace std;

namespace minimum_space_wasted_from_packaging {
    class Solution {
    public:
        int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_SPACE_WASTED_FROM_PACKAGING_H
