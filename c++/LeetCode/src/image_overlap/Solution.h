//
// Created by dexhacker on 10/27/22.
//

#ifndef LEETCODE_IMAGE_OVERLAP_H
#define LEETCODE_IMAGE_OVERLAP_H

#include <iostream>
#include <vector>

using namespace std;

namespace image_overlap {
    class Solution {
    public:
        int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2);
        void test();
    };
}

#endif //LEETCODE_IMAGE_OVERLAP_H
