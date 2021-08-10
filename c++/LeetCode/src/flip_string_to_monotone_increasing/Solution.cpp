//
// Created by dexhacker on 8/10/21.
//

#include "Solution.h"
#include <cassert>

int flip_string_to_monotone_increasing::Solution::minFlipsMonoIncr(string s) {
    int answer = 0;
    int index = 0;
    while (s[index] == '0') ++index;

    int ones = 0;
    int zeros = 0;
    for (; index < s.size(); ++index) {
        if (s[index] == '1') ++ones;
        if (s[index] == '0') ++zeros;

        if (zeros > ones) {
            answer += ones;
            ones = 0;
            zeros = 0;

        }
    }

    return answer + zeros;
}

void flip_string_to_monotone_increasing::Solution::test() {
    assert(minFlipsMonoIncr("00110") == 1);

    cout << "minFlipsMonoIncr completed!" << endl;
}
