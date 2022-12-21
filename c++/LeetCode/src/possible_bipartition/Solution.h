//
// Created by dexhacker on 12/21/22.
//

#ifndef LEETCODE_POSSIBLE_BIPARTITION_H
#define LEETCODE_POSSIBLE_BIPARTITION_H

#include <iostream>
#include <vector>

using namespace std;

namespace possible_bipartition {
    class Solution {
    public:
        bool possibleBipartition(int n, vector<vector<int>>& dislikes);
        void test();
    };
}

#endif //LEETCODE_POSSIBLE_BIPARTITION_H
