//
// Created by Фарид Абдугалыев on 22.12.2021.
//

#ifndef LEETCODE_NUMBERS_AT_MOST_N_GIVEN_DIGIT_SET_H
#define LEETCODE_NUMBERS_AT_MOST_N_GIVEN_DIGIT_SET_H

#include <iostream>
#include <vector>

using namespace std;

namespace numbers_at_most_n_given_digit_set {
    class Solution {
    public:
        int atMostNGivenDigitSet(vector<string>& digits, int n);
        void test();
    };
}

#endif //LEETCODE_NUMBERS_AT_MOST_N_GIVEN_DIGIT_SET_H
