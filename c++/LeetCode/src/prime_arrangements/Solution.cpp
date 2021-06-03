//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <vector>
#include <cmath>
#include <cassert>

int prime_arrangements::Solution::numPrimeArrangements(int n) {
    int p = 0, d = 1;
    long fac_p = 1, fac_d = 1;
    vector<bool> used(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (used[i]) {
            d++;
            fac_d *= d;
            fac_d %= (int)pow(10, 9) + 7;
            continue;
        }
        p++;
        fac_p *= p;
        fac_p %= (int)pow(10, 9) + 7;
        for (int j = i; j <= n; j += i) used[j] = true;
    }
    return (int)((fac_d * fac_p) % ((int)pow(10, 9) + 7));
}

void prime_arrangements::Solution::test() {
    assert(numPrimeArrangements(100) == 682289015);

    cout << "numPrimeArrangements completed!" << endl;
}
