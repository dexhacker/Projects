//
// Created by dexhacker on 3/11/21.
//

#include "Solution.h"
#include <cassert>

string to_lower_case::Solution::toLowerCase(string str) {
    for (char & i : str) {
        if (i > 64 && i < 91) {
            i = i - 'A' + 'a';
        }
    }
    return str;
}

void to_lower_case::Solution::test() {
    assert(toLowerCase("Hello") == "hello");
    assert(toLowerCase("here") == "here");
    assert(toLowerCase("LOVELY") == "lovely");

    cout << "toLowerCase completed!" << endl;
}
