//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cassert>

int sum_of_two_integers::Solution::getSum(int a, int b) {
    int answer = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i) and b & (1 << i)) {
            if (i + 1 < 32) answer |= 1 << (i + 1);
        } else if (a & (1 << i) or b & (1 << i)) {
            if (answer & (1 << i)) {
                answer ^= 1 << i;
                if (i + 1 < 32) answer |= 1 << (i + 1);
            } else {
                answer |= 1 << i;
            }
        }
    }
    return answer;
}

void sum_of_two_integers::Solution::test() {
    assert(getSum(2, 3) == 5);

    cout << "getSum completed!" << endl;
}
