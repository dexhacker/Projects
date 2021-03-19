//
// Created by dexhacker on 3/15/21.
//

#include "Solution.h"
#include <cassert>

string zigzag_conversion::Solution::convert(string s, int numRows) {
    if (numRows == 1) return s;

    int step [2] = {(numRows - 1) * 2, (numRows - 1) * 2};
    string ans;
    for (int i = 0; i < numRows; i++) {
        int index = i;
        int step_cont = 0;
        while (index < s.size()) {
            ans += s[index];
            index += step[step_cont % 2];
            step_cont++;
        }
        step[0] -= 2;
        step[1] = (numRows - 1) * 2 - step[0];

        if (step[0] == 0) {
            step[0] = (numRows - 1) * 2;
            step[1] = (numRows - 1) * 2;
        }
    }
    return ans;
}

void zigzag_conversion::Solution::test() {
    assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(convert("A", 1) == "A");
    assert(convert("AA", 1) == "AA");
    assert(convert("AA", 2) == "AA");

    std::cout << "convert completed!" << std::endl;
}
