//
// Created by dexhacker on 1/2/23.
//

#include "Solution.h"
#include <cassert>

bool detect_capital::Solution::detectCapitalUse(string word) {
    if (word.size() < 2) return true;

    int isCapital = (word[0] > 92) ? 1 : -1;
    if (isCapital == 1 && word[1] < 92) return false;
    isCapital = (word[1] > 92) ? 1 : 0;

    for (int i = 1; i < word.size(); i++) {
        if (isCapital == 0 && word[i] > 92) return false;
        if (isCapital == 1 && word[i] < 92) return false;
    }
    return true;
}

void detect_capital::Solution::test() {
    assert(detectCapitalUse("USA") == true);
    assert(detectCapitalUse("FlaG") == false);

    cout << "detectCapitalUse completed!" << endl;
}
