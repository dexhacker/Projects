//
// Created by dexhacker on 9/24/22.
//

#include "Solution.h"
#include <cassert>

int concatenation_of_consecutive_binary_numbers::Solution::concatenatedBinary(int n) {
    long ans = 0, MOD = 1e9 + 7, len = 0;
    for (int i = 1; i <= n; ++i) {
        if(__builtin_popcount(i) == 1) ++len;
        ans = ((ans << len) % MOD + i) % MOD;
    }
    return ans;
}

void concatenation_of_consecutive_binary_numbers::Solution::test() {
    assert(concatenatedBinary(12) == 505379714);

    cout << "concatenatedBinary completed!" << endl;
}
