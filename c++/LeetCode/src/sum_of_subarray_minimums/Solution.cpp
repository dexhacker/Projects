//
// Created by dexhacker on 11/28/22.
//

#include "Solution.h"
#include <cassert>

int sum_of_subarray_minimums::Solution::sumSubarrayMins(vector<int> &n) {
    vector<long> s, sums(n.size(),0);
    long j, res=0, mod = 1000000007;
    for (int i = 0; i < n.size(); ++i) {
        while (!s.empty() && n[s.back()] > n[i])
            s.pop_back();
        j = !s.empty() ? s.back() : -1;

        sums[i] = ((j>=0?sums[j]:0) + (i-j)*n[i]) % mod;
        s.push_back(i);
    }

    for (int i = 0; i < sums.size(); ++i)
        res = (res + sums[i]) % mod;
    return res;
}

void sum_of_subarray_minimums::Solution::test() {
    vector<int> test {3, 1, 2, 4};
    assert(sumSubarrayMins(test) == 17);

    cout << "sumSubarrayMins completed!" << endl;
}
