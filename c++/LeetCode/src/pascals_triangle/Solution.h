//
// Created by dexhacker on 5/22/21.
//

#ifndef LEETCODE_PASCALS_TRIANGLE_H
#define LEETCODE_PASCALS_TRIANGLE_H

#include <iostream>
#include <vector>

using namespace std;

namespace pascals_triangle {
    class Solution {
    public:
        vector<vector<int>> generate(int numRows);
        void test();
    };
}

#endif //LEETCODE_PASCALS_TRIANGLE_H
