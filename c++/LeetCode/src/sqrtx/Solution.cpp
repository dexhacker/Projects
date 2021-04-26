//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int sqrtx::Solution::mySqrt(int x) {
    long long l = 0, r = x;
    while (l < r) {
        long long m = (l + r + 1) / 2;
        if (m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

void sqrtx::Solution::test() {
    assert(mySqrt(4) == 2);
    assert(mySqrt(8) == 2);
    assert(mySqrt(9) == 3);
    assert(mySqrt(25) == 5);
    assert(mySqrt(24) == 4);

    cout << "mySqrt completed!" << endl;
}