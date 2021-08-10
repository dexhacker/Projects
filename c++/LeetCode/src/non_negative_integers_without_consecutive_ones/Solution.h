//
// Created by dexhacker on 7/26/21.
//

#ifndef LEETCODE_NON_NEGATIVE_INTEGERS_WITHOUT_CONSECUTIVE_ONES_H
#define LEETCODE_NON_NEGATIVE_INTEGERS_WITHOUT_CONSECUTIVE_ONES_H

#include <iostream>
#include <vector>

using namespace std;

namespace non_negative_integers_without_consecutive_ones {
    class Solution {
    public:
        int findIntegers(int n);
        void test();

    private:
        int number = 0;
        int bytes = 31;
        vector<pair<long, long>> invalidNumbers;

        void updateToValid();
        void calculateInvalidNumbers();
    };
}


#endif //LEETCODE_NON_NEGATIVE_INTEGERS_WITHOUT_CONSECUTIVE_ONES_H
