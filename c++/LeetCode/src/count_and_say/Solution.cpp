//
// Created by dexhacker on 9/14/22.
//

#include "Solution.h"
#include <cassert>

string count_and_say::Solution::countAndSay(int n) {
    if (n == 1) return "1";

    string s = countAndSay(n - 1);
    string new_s;

    char prev;
    int count = 0;
    for (char c : s) {
        if (c == prev) {
            count++;
        } else {
            if (count > 0) new_s += to_string(count) + prev;
            prev = c;
            count = 1;
        }
    }

    return new_s + to_string(count) + prev;
}

void count_and_say::Solution::test() {
    assert(countAndSay(1) == "1");
    assert(countAndSay(4) == "1211");

    cout << "countAndSay completed!" << endl;
}
