//
// Created by dexhacker on 1/12/21.
//

#include "Solution.h"
#include <cassert>
#include <iostream>


int task::Solution::sum(int a, int b) {
    return a + b;
}

void task::Solution::test() {
    assert(sum(2, 3) == 5);
    assert(sum(2, 3) == 6);
    std::cout << "Tests completed!" << std::endl;
}
