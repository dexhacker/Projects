//
// Created by dexhacker on 12/28/22.
//

#include "Solution.h"
#include <cassert>

int remove_stones_to_minimize_the_total::Solution::minStoneSum(vector<int> &piles, int k) {
    sort(piles.begin(), piles.end());
    int n = (piles.back() + 1) / 2;
    int i = piles.size() - 1;
    while (k > 0) {
        if (piles[i] < n) {
            sort(piles.begin(), piles.end());
            n = (piles.back() + 1) / 2;
            i = piles.size() - 1;
        }
        piles[i] = (piles[i] + 1) / 2;
        if (i > 0) i--;
        k--;
    }
    int sum = 0;
    for (int j : piles) sum += j;
    return sum;
}

void remove_stones_to_minimize_the_total::Solution::test() {
    vector<int> piles {5, 4, 9};
    assert(minStoneSum(piles, 2) == 12);

    cout << "minStoneSum completed!" << endl;
}
