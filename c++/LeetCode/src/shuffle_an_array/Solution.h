//
// Created by dexhacker on 7/20/21.
//

#ifndef LEETCODE_SHUFFLE_AN_ARRAY_H
#define LEETCODE_SHUFFLE_AN_ARRAY_H

#include <iostream>
#include <vector>

using namespace std;

namespace shuffle_an_array {
    class Solution {
    public:
        static void test();

        Solution(vector<int> &nums);

        vector<int> reset();

        vector<int> shuffle();

    private:
        vector<int> numbers;
    };
}

#endif //LEETCODE_SHUFFLE_AN_ARRAY_H
