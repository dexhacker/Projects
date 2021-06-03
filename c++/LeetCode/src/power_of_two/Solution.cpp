//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <cassert>

bool power_of_two::Solution::isPowerOfTwo(int n) {
    if (n < 1) return false;

    int j = 1;
    for (int i = 0; i < 31; i++) {
        if (n == j) return true;
        if (j > n) return false;
        j = j << 1;
    }

    return false;
}

void power_of_two::Solution::test() {
    assert(isPowerOfTwo(16) == true);

    cout << "isPowerOfTwo completed!" << endl;
}
