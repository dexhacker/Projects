//
// Created by dexhacker on 7/1/21.
//

#include "Solution.h"
#include <cassert>

int gray_code::Solution::fillAnswer(int n, int number) {
    if (n == 1) {
        answer.push_back(number);
        number ^= 1;
        answer.push_back(number);
        return number;
    }

    int newNumber = fillAnswer(n - 1, number);
    newNumber ^= (1 << (n - 1));
    newNumber = fillAnswer(n - 1, newNumber);
    return newNumber;
}

vector<int> gray_code::Solution::grayCode(int n) {
    fillAnswer(n, 0);
    return answer;
}

void gray_code::Solution::test() {
    vector<int> ans {0, 1, 3, 2};
    assert(grayCode(2) == ans);

    cout << "grayCode completed!" << endl;
}
