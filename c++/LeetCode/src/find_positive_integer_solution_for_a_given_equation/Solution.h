//
// Created by dexhacker on 4/22/21.
//

#ifndef LEETCODE_FIND_POSITIVE_INTEGER_SOLUTION_FOR_A_GIVEN_EQUATION_H
#define LEETCODE_FIND_POSITIVE_INTEGER_SOLUTION_FOR_A_GIVEN_EQUATION_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_positive_integer_solution_for_a_given_equation {
    class CustomFunction {
    public:
        int f(int x, int y) {
            return x + y;
        }
    };

    class Solution {
    public:
        vector<vector<int>> findSolution(CustomFunction& customfunction, int z);
        void test();
    };
}

#endif //LEETCODE_FIND_POSITIVE_INTEGER_SOLUTION_FOR_A_GIVEN_EQUATION_H
