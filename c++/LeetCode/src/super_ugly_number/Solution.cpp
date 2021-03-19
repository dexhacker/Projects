//
// Created by dexhacker on 3/11/21.
//

#include "Solution.h"
#include <cassert>

int super_ugly_number::Solution::nthSuperUglyNumber(int n, vector<int> &primes) {
    if (n == 1)
        return 1;

    vector<int> ans = {1};
    vector<int> indexes(primes.size());
    vector<int> copy_primes = primes;
    for (int i = 1; i < n; i++) {
        vector<int> min_indexes = {0};
        int min = copy_primes[0];
        for (int j = 1; j < copy_primes.size(); j++) {
            if (min > copy_primes[j]) {
                min_indexes.clear();
                min_indexes.push_back(j);
                min = copy_primes[j];
            } else if (min == copy_primes[j]) {
                min_indexes.push_back(j);
            }
        }

        ans.push_back(min);

        for (int index : min_indexes) {
            indexes[index]++;
            copy_primes[index] = primes[index] * ans[indexes[index]];
        }
    }

    return ans[ans.size() - 1];
}

void super_ugly_number::Solution::test() {
    vector<int> test1 = {2, 7, 13, 19};
    assert(nthSuperUglyNumber(12, test1) == 32);

    vector<int> test2 = {2, 3, 5};
    assert(nthSuperUglyNumber(1, test2) == 1);

    vector<int> test3 = {3, 5, 7, 11, 19, 23, 29, 41, 43, 47};
    assert(nthSuperUglyNumber(15, test3) == 35);

    cout << "nthSuperUglyNumber completed!" << endl;
}
