//
// Created by dexhacker on 9/16/22.
//

#include "Solution.h"
#include <cassert>

bool divisor_game::Solution::divisorGame(int n) {
    return n % 2 == 0;
}

void divisor_game::Solution::test() {
    assert(divisorGame(2) == true);
    assert(divisorGame(3) == false);

    cout << "divisorGame completed!" << endl;
}
