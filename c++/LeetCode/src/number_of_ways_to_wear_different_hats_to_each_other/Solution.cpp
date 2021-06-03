//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cassert>

int number_of_ways_to_wear_different_hats_to_each_other::Solution::numberWays(vector<vector<int>> &hats) {
    vector<vector<int>> persons(40);
    const int n(hats.size()), mod(1e9 + 7);
    vector<int> masks(1 << n);
    masks[0] = 1;

    for (int i = 0; i < n; ++i)
        for (const int& h: hats[i])
            persons[h - 1].emplace_back(i);

    for (int i = 0; i < 40; ++i)
        for (int j = (1 << n) - 1; j >= 0; --j)
            for (const int& p: persons[i])
                if ((j & (1 << p)) == 0) {
                    masks[j | (1 << p)] += masks[j];
                    masks[j | (1 << p)] %= mod;
                }
    return masks[(1 << n) - 1];
}

void number_of_ways_to_wear_different_hats_to_each_other::Solution::test() {
    vector<vector<int>> test {{1, 2, 3}, {2, 3, 5, 6}, {1, 3, 7, 9}, {1, 8, 9}, {2, 5, 7}};
    assert(numberWays(test) == 111);

    cout << "numberWays completed!" << endl;
}
