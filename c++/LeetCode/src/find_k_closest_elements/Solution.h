//
// Created by dexhacker on 7/2/21.
//

#ifndef LEETCODE_FIND_K_CLOSEST_ELEMENTS_H
#define LEETCODE_FIND_K_CLOSEST_ELEMENTS_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_k_closest_elements {
    class Solution {
    public:
        int closestIndex(vector<int>& arr, int x, int start, int finish);
        vector<int> findClosestElements(vector<int>& arr, int k, int x);
        void test();
    };
}

#endif //LEETCODE_FIND_K_CLOSEST_ELEMENTS_H
