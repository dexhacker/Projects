//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <cassert>

double powx_n::Solution::myPowAbs(double x, long n) {
    if (hm.count(n) > 0) return hm[n];

    if (n % 2 == 0) {
        hm[n] = myPow(x, n / 2) * myPow(x, n / 2);
        return hm[n];
    }

    hm[n] = myPow(x, n / 2) * myPow(x, n / 2) * x;
    return hm[n];
}

double powx_n::Solution::myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return myPowAbs(1 / x, abs(n));

    return myPowAbs(x, abs(n));
}

void powx_n::Solution::test() {
    assert(myPow(2, 10) == 1024);

    cout << "myPow completed!" << endl;
}
