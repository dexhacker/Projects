//
// Created by dexhacker on 12/12/22.
//

#include "Solution.h"
#include <cassert>

int climbing_stairs::Solution::climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 0, b = 1, c = 2;
    for (int i = 3; i <= n; i++) {
        int tmp = b + c;
        a = b;
        b = c;
        c = tmp;
    }
    return c;
}

void climbing_stairs::Solution::test() {
    assert(climbStairs(2) == 2);
    assert(climbStairs(3) == 3);

    cout << "climbStairs completed!" << endl;
}
