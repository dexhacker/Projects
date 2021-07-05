//
// Created by dexhacker on 7/2/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int fibonacci_number::Solution::fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    return fib[n];
}

void fibonacci_number::Solution::test() {
    assert(fib(4) == 3);

    cout << "fib completed!" << endl;
}
