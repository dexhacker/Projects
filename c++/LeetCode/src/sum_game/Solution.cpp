//
// Created by dexhacker on 7/12/21.
//

#include "Solution.h"
#include <cassert>

bool sum_game::Solution::sumGame(string num) {
    double res = 0, n = num.length();
    for (int i = 0; i < n; ++i)
        res += (i < n / 2 ? 1 : -1) * (num[i] == '?' ? 4.5 : num[i] - '0');
    return res != 0.0;
}

void sum_game::Solution::test() {
    assert(sumGame("5023") == false);

    cout << "sumGame completed!" << endl;
}
