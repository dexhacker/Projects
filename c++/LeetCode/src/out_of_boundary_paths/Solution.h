//
// Created by dexhacker on 6/25/21.
//

#ifndef LEETCODE_OUT_OF_BOUNDARY_PATHS_H
#define LEETCODE_OUT_OF_BOUNDARY_PATHS_H

#include <iostream>

using namespace std;

namespace out_of_boundary_paths {
    class Solution {
    public:
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn);
        void test();
    };
}

#endif //LEETCODE_OUT_OF_BOUNDARY_PATHS_H
