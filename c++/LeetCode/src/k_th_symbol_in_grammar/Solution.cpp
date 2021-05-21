//
// Created by dexhacker on 5/1/21.
//

#include "Solution.h"
#include <cassert>

int k_th_symbol_in_grammar::Solution::kthGrammar(int N, int K) {
    if (N == 1) return 0;

    if (K % 2 == 0) {
        return (kthGrammar(N - 1, K / 2) == 0) ? 1 : 0;
    } else {
        return (kthGrammar(N - 1, (K + 1) / 2) == 0) ? 0 : 1;
    }
}

void k_th_symbol_in_grammar::Solution::test() {
    assert(kthGrammar(1, 1) == 0);
    assert(kthGrammar(2, 1) == 0);
    assert(kthGrammar(2, 2) == 1);
    assert(kthGrammar(4, 5) == 1);
    assert(kthGrammar(30, 434991989) == 0);
    assert(kthGrammar(3, 3) == 1);

    cout << "kthGrammar completed!" << endl;
}
