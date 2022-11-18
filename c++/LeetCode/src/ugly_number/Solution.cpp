//
// Created by dexhacker on 11/18/22.
//

#include "Solution.h"
#include <cassert>

bool ugly_number::Solution::isUgly(int n) {
    if (n <= 0) return false;
    int new_n = n;
    n = -1;
    while (n != new_n) {
        n = new_n;
        if (n % 5 == 0) {
            new_n = n / 5;
        } else if (n % 3 == 0) {
            new_n = n / 3;
        } else if (n % 2 == 0) {
            new_n = n / 2;
        }
    }
    return new_n == 1;
}

void ugly_number::Solution::test() {
    assert(isUgly(100) == true);

    cout << "isUgly completed!" << endl;
}
