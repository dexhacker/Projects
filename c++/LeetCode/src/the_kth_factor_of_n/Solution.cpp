//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int the_kth_factor_of_n::Solution::kthFactor(int n, int k) {
    vector<int> list;
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (count == k) return i;
            list.push_back(i);
            if (n / i != i) list.push_back(n / i);
        }
    }
    if (list.size() < k) return -1;

    sort(list.begin(), list.end());
    return list[k - 1];
}

void the_kth_factor_of_n::Solution::test() {
    assert(kthFactor(1000, 3) == 4);

    cout << "kthFactor completed!" << endl;
}
