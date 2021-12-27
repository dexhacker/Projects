//
// Created by Фарид Абдугалыев on 27.12.2021.
//

#include "Solution.h"
#include <cassert>

int complement_of_base_10_integer::Solution::bitwiseComplement(int n) {
    if (n == 0) return 1;

    int answer = 0;

    bool has_one = false;
    for (int i = 31; i >= 0; i--) {
        if ((n & (1 << i)) != 0) {
            has_one = true;
        }

        if (has_one) {
            if ((n & (1 << i)) == 0) {
                answer = answer ^ (1 << i);
            }
        }
    }

    return answer;
}

void complement_of_base_10_integer::Solution::test() {
    assert(bitwiseComplement(5) == 2);
    assert(bitwiseComplement(7) == 0);
    assert(bitwiseComplement(10) == 5);

    cout << "bitwiseComplement completed!" << endl;
}
