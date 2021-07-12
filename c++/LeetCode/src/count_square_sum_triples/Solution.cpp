//
// Created by dexhacker on 7/12/21.
//

#include "Solution.h"
#include <cassert>

int count_square_sum_triples::Solution::countTriples(int n) {
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int l = j + 1; l <= n; ++l) {
                if (i * i + j * j == l * l) {
                    answer += 2;
                }
            }
        }
    }
    return answer;
}

void count_square_sum_triples::Solution::test() {
    assert(countTriples(10) == 4);

    cout << "countTriples completed!" << endl;
}
