//
// Created by dexhacker on 6/6/21.
//

#ifndef LEETCODE_DETERMINE_WHETHER_MATRIX_CAN_BE_OBTAINED_BY_ROTATION_H
#define LEETCODE_DETERMINE_WHETHER_MATRIX_CAN_BE_OBTAINED_BY_ROTATION_H

#include <iostream>
#include <vector>

using namespace std;

namespace determine_whether_matrix_can_be_obtained_by_rotation {
    class Solution {
    public:
        vector<vector<int>> move(vector<vector<int>>& mat);
        bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target);
        bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target);
        void test();
    };
}

#endif //LEETCODE_DETERMINE_WHETHER_MATRIX_CAN_BE_OBTAINED_BY_ROTATION_H
