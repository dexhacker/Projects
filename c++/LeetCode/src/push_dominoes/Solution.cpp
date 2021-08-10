//
// Created by dexhacker on 7/22/21.
//

#include "Solution.h"
#include <cassert>

string push_dominoes::Solution::pushDominoes(string dominoes) {
    int f = 0, s = 0;
    int size = 0;
    while (s < dominoes.size()) {
        if (dominoes[s] == '.') {
            ++size;
        } else if (dominoes[s] == 'R') {
            while (f < s) {
                ++f;
                if (dominoes[f - 1] == 'R') dominoes[f] = dominoes[f - 1];
            }
        } else {
            if (dominoes[f] == 'R') {
                bool odd = ((s - (f + 1)) % 2 != 0);

                int middle = (s - (f + 1)) / 2;
                for (int i = 0; i < middle; ++i) {
                    ++f;
                    dominoes[f] = 'R';
                }
                if (odd) ++f;
                for (int i = 0; i < middle; ++i) {
                    ++f;
                    dominoes[f] = 'L';
                }
                ++f;
            } else {
                while (f < s) {
                    dominoes[f] = 'L';
                    ++f;
                }
                ++f;
            }
        }
        ++s;
    }

    if (dominoes[f] == 'R') {
        while(f < s) {
            ++f;
            dominoes[f] = 'R';
        }
    }
    return dominoes;
}

void push_dominoes::Solution::test() {
    assert(pushDominoes(".L.R...LR..L..") == "LL.RR.LLRRLL..");

    cout << "pushDominoes completed!" << endl;
}
