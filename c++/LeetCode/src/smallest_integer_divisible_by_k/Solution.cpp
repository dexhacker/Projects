//
// Created by Фарид Абдугалыев on 30.12.2021.
//

#include "Solution.h"
#include <cassert>

int smallest_integer_divisible_by_k::Solution::smallestRepunitDivByK(int k) {
    int remainder = 0;
    for (int i = 1; i <= k; i++) {
        remainder = (remainder * 10 + 1) % k;
        if (remainder == 0) return i;
    }

    return -1;
}

void smallest_integer_divisible_by_k::Solution::test() {
    assert(smallestRepunitDivByK(1) == 1);
    assert(smallestRepunitDivByK(2) == -1);
    assert(smallestRepunitDivByK(3) == 3);

    cout << "smallestRepunitDivByK completed!" << endl;
}
