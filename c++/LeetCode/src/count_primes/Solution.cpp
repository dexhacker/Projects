//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int count_primes::Solution::countPrimes(int n) {
    int count = 0;
    vector<bool> used(n + 1, false);
    for (int i = 2; i < n; i++) {
        if (used[i]) continue;
        count++;
        for (int j = i; j <= n; j += i) used[j] = true;
    }
    return count;
}

void count_primes::Solution::test() {
    assert(countPrimes(10) == 4);

    cout << "countPrimes completed!" << endl;
}
