//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cassert>

int simplified_fractions::Solution::gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<string> simplified_fractions::Solution::simplifiedFractions(int n) {
    vector<string> answer;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (gcd(i, j) == 1) {
                string tmp = to_string(i);
                tmp += '/';
                tmp += to_string(j);
                answer.push_back(tmp);
            }
        }
    }
    return answer;
}

void simplified_fractions::Solution::test() {
    vector<string> answer {"1/2", "1/3", "1/4", "2/3", "3/4"};
    assert(simplifiedFractions(4) == answer);

    cout << "simplifiedFractions completed!" << endl;
}
