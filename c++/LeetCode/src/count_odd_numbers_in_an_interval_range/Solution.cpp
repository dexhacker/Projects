//
// Created by dexhacker on 2/13/23.
//

#include "Solution.h"
#include <cassert>

int count_odd_numbers_in_an_interval_range::Solution::countOdds(int low, int high) {
    return (high % 2 == 1 || low % 2 == 1) ? (high - low) / 2 + 1 : (high - low) / 2;
}

void count_odd_numbers_in_an_interval_range::Solution::test() {
    assert(countOdds(3, 7) == 3);

    cout << "countOdds completed!" << endl;
}
