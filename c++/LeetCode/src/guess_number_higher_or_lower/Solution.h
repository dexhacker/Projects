//
// Created by dexhacker on 11/16/22.
//

#ifndef LEETCODE_GUESS_NUMBER_HIGHER_OR_LOWER_H
#define LEETCODE_GUESS_NUMBER_HIGHER_OR_LOWER_H

#include <iostream>

using namespace std;

namespace guess_number_higher_or_lower {
    class Solution {
    public:
        int guessNumber(int n);
        void test();

    private:
        int guess(int num);
    };
}

#endif //LEETCODE_GUESS_NUMBER_HIGHER_OR_LOWER_H
