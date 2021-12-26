//
// Created by Фарид Абдугалыев on 26.12.2021.
//

#ifndef LEETCODE_K_CLOSEST_POINTS_TO_ORIGIN_H
#define LEETCODE_K_CLOSEST_POINTS_TO_ORIGIN_H

#include <iostream>
#include <vector>

using namespace std;

namespace k_closest_points_to_origin {
    class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k);
        void test();
    };
}

#endif //LEETCODE_K_CLOSEST_POINTS_TO_ORIGIN_H
