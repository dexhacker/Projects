//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <cassert>

bool power_of_two::Solution::isPowerOfTwo(int n) {
    if (n < 1) return false;

    return !(n & (n - 1));
}

void power_of_two::Solution::test() {
    assert(isPowerOfTwo(16) == true);

    cout << "isPowerOfTwo completed!" << endl;
}
