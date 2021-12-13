//
// Created by Фарид Абдугалыев on 13.12.2021.
//

#include "Solution.h"
#include <cassert>

int consecutive_characters::Solution::maxPower(string s) {
    char currentChar;
    int currentLength = 0;
    int maxLength = 0;
    for (int i = 0; i< s.size(); i++) {
        if (currentChar == s[i]) {
            currentLength++;
        } else {
            currentChar = s[i];
            if (currentLength > maxLength) maxLength = currentLength;
            currentLength = 1;
        }
    }
    if (currentLength > maxLength) maxLength = currentLength;

    return maxLength;
}

void consecutive_characters::Solution::test() {
    assert(maxPower("leetcode") == 2);
    assert(maxPower("abbcccddddeeeeedcba") == 5);
    assert(maxPower("triplepillooooow") == 5);
    assert(maxPower("hooraaaaaaaaaaay") == 11);
    assert(maxPower("tourist") == 1);
    assert(maxPower("abbcccddddeeeeedcbadddd") == 5);

    cout << "maxPower completed!" << endl;
}
