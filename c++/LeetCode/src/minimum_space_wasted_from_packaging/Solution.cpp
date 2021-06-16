//
// Created by dexhacker on 6/7/21.
//

#include "Solution.h"
#include <cassert>

int minimum_space_wasted_from_packaging::Solution::minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
    sort(packages.begin(), packages.end());
    long res = INT64_MAX, mod = 1e9 + 7, sum_packages = 0;
    for (int a : packages)
        sum_packages += a;
    for (auto& B : boxes) {
        sort(B.begin(), B.end());
        if (B[B.size() - 1] < packages[packages.size() - 1]) continue;
        long cur = 0, i = 0, j;
        for (int b : B) {
            j = upper_bound(packages.begin(), packages.end(), b) - packages.begin();
            cur += b * (j - i);
            i = j;
        }
        res = min(res, cur);
    }
    return res < INT64_MAX ? (res - sum_packages) % mod : -1;
}

void minimum_space_wasted_from_packaging::Solution::test() {
    vector<int> packages {2, 3, 5};
    vector<vector<int>> boxes {{4, 8}, {2, 8}};
    assert(minWastedSpace(packages, boxes) == 6);

    cout << "minWastedSpace completed!" << endl;
}
