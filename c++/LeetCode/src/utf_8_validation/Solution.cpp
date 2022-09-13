//
// Created by dexhacker on 9/13/22.
//

#include "Solution.h"
#include <cassert>

bool utf_8_validation::Solution::validUtf8(vector<int> &data) {
    int byte = 0;

    for (int i : data) {
        if (byte == 0) {
            if (i < 128) continue;

            if (i < 192) return false;

            if (i < 224) {
                byte = 1;
                continue;
            }

            if (i < 240) {
                byte = 2;
                continue;
            }

            if (i < 248) {
                byte = 3;
                continue;
            }

            return false;
        }

        if (128 <= i && i < 192) {
            byte--;
            continue;
        }

        return false;
    }

    return byte == 0;
}

void utf_8_validation::Solution::test() {
    vector<int> test1 {197, 130, 1};
    assert(validUtf8(test1) == true);

    vector<int> test2 {235, 140, 4};
    assert(validUtf8(test2) == false);

    cout << "validUtf8 completed!" << endl;
}
