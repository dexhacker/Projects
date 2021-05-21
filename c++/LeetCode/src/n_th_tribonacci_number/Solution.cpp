//
// Created by dexhacker on 4/29/21.
//

#include "Solution.h"
#include <cassert>

int n_th_tribonacci_number::Solution::tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    int i1 = 0, i2 = 1, i3 = 1;
    while (n > 2) {
        int tmp = i3;
        i3 += i2 + i1;
        i1 = i2;
        i2 = tmp;
        n--;
    }
    return i3;
}

void n_th_tribonacci_number::Solution::test() {
    assert(tribonacci(4) == 4);
    assert(tribonacci(25) == 1389537);
    assert(tribonacci(1) == 1);
    assert(tribonacci(2) == 1);
    assert(tribonacci(37) == 2082876103);

    cout << "tribonacci completed!" << endl;
}