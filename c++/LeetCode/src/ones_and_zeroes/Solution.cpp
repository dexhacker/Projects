//
// Created by dexhacker on 5/1/21.
//

#include "Solution.h"
#include <cassert>

int ones_and_zeroes::Solution::findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
    int numZeroes, numOnes;

    for (auto &s : strs) {
        numZeroes = numOnes = 0;
        for (auto c : s) {
            if (c == '0')
                numZeroes++;
            else if (c == '1')
                numOnes++;
        }

        for (int i = m; i >= numZeroes; i--) {
            for (int j = n; j >= numOnes; j--) {
                memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
            }
        }
    }
    return memo[m][n];
}

void ones_and_zeroes::Solution::test() {
    vector<string> test1 {"10", "0001", "111001", "1", "0"};
    assert(findMaxForm(test1, 5, 3) == 4);

    vector<string> test2 {"10", "0", "1"};
    assert(findMaxForm(test2, 1, 1) == 2);

    vector<string> test3 {"1", "11", "10", "1"};
    assert(findMaxForm(test3, 1, 3) == 3);

    cout << "findMaxForm completed!" << endl;
}
