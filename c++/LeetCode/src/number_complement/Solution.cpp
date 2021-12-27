//
// Created by Фарид Абдугалыев on 27.12.2021.
//

#include "Solution.h"
#include <cassert>

int number_complement::Solution::findComplement(int num) {
    if (num == 0) return 1;

    int answer = 0;

    bool has_one = false;
    for (int i = 31; i >= 0; i--) {
        if ((num & (1 << i)) != 0) {
            has_one = true;
        }

        if (has_one) {
            if ((num & (1 << i)) == 0) {
                answer = answer ^ (1 << i);
            }
        }
    }

    return answer;
}

void number_complement::Solution::test() {
    assert(findComplement(5) == 2);
    assert(findComplement(1) == 0);

    cout << "findComplement completed!" << endl;
}
