//
// Created by dexhacker on 11/7/22.
//

#include "Solution.h"
#include <cassert>

int maximum_69_number::Solution::maximum69Number(int num) {
    string number = to_string(num);
    for (int i = 0; i < number.size(); i++) {
        if (number[i] == '6') {
            number[i] = '9';
            return stoi(number);
        }
    }

    return num;
}

void maximum_69_number::Solution::test() {
    assert(maximum69Number(9669) == 9969);

    cout << "maximum69Number completed!" << endl;
}
