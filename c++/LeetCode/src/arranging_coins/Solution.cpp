//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int arranging_coins::Solution::arrangeCoins(int n) {
    long long left = 0, right = n;
    while (left < right) {
        long long m = (left + right + 1) / 2;
        long long f = m * (m + 1) / 2;
        if (f > n)
            right = m - 1;
        else
            left = m;
    }
    return left;
}

void arranging_coins::Solution::test() {
    assert(arrangeCoins(5) == 2);
    assert(arrangeCoins(8) == 3);
    assert(arrangeCoins(1) == 1);

    cout << "arrangeCoins completed!" << endl;
}
