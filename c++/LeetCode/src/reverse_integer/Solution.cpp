//
// Created by dexhacker on 4/27/21.
//

#include "Solution.h"
#include <cassert>

int reverse_integer::Solution::reverse(int x) {
    char minus;
    string x_string = to_string(x);
    if (x_string[0] == '-') {
        minus = '-';
    }
}

void reverse_integer::Solution::test() {
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    assert(reverse(0) == 0);

    cout << "reverse completed!" << endl;
}
