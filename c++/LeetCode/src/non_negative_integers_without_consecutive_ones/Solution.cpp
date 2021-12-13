//
// Created by dexhacker on 7/26/21.
//

#include "Solution.h"
#include <cassert>

void non_negative_integers_without_consecutive_ones::Solution::updateToValid() {
    bool hasOne = false;
    bool isFixed = false;

    for (int i = 31; i >= 0; --i) {
        if (isFixed) {
            if ((number & (1 << i)) > 0) {
                number -= (1 << i);
            }
            continue;
        }
        if (hasOne) {
            if ((number & (1 << i)) > 0) {
                number += (1 << (i + 2));
                number -= (1 << (i + 1));
                number -= (1 << i);
                isFixed = true;
                continue;
            }
        }
        if ((number & (1 << i)) > 0) {
            hasOne = true;
        } else {
            hasOne = false;
        }
    }
}

void non_negative_integers_without_consecutive_ones::Solution::calculateInvalidNumbers() {
    invalidNumbers.push_back({0, 0});
    invalidNumbers.push_back({0, 2});
    invalidNumbers.push_back({1, 4});
    for (int i = 2; i <= bytes; ++i) {
        int prev = invalidNumbers.back().first;
        auto p = invalidNumbers[invalidNumbers.size() - 2];
        long invalidNumber = prev + p.first + p.second;
        long count = invalidNumbers.back().second * 2;
        invalidNumbers.push_back({invalidNumber, count});
    }
}

int non_negative_integers_without_consecutive_ones::Solution::findIntegers(int n) {
    number = n;
    updateToValid();

    calculateInvalidNumbers();

    int invalidNumber = 0;
    if (number == n) --invalidNumber;

    for (int i = 0; i <= bytes; ++i) {
        if ((number & (1 << i)) > 0) {
            invalidNumber += invalidNumbers[i].first;
        }
    }
    return number - invalidNumber;
}

void non_negative_integers_without_consecutive_ones::Solution::test() {
    assert(findIntegers(5) == 5);

    cout << "findIntegers completed!" << endl;
}
