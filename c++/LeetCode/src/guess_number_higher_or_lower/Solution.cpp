//
// Created by dexhacker on 11/16/22.
//

#include "Solution.h"
#include <cassert>

int guess_number_higher_or_lower::Solution::guess(int num) {
    if (num == 6) return 0;
    if (num > 6) return -1;
    return 1;
}

int guess_number_higher_or_lower::Solution::guessNumber(int n) {
    int half_int_min = INT_MIN / 2;
    int l = 1 + half_int_min;
    int r = n + half_int_min;
    while (true) {
        int pick = (l + r) / 2;
        int answer = guess(pick - half_int_min);
        if (answer == 0) return pick - half_int_min;
        if (answer == 1) l = pick + 1;
        else r = pick - 1;
    }

    return -1;
}

void guess_number_higher_or_lower::Solution::test() {
    assert(guessNumber(10) == 6);

    cout << "guessNumber completed!" << endl;
}
