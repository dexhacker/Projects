//
// Created by dexhacker on 1/6/23.
//

#include "Solution.h"
#include <cassert>

int maximum_ice_cream_bars::Solution::maxIceCream(vector<int> &costs, int coins) {
    int answer = 0;
    sort(costs.begin(), costs.end());
    for (int i = 0; i < costs.size(); i++) {
        if (coins < costs[i]) break;

        answer++;
        coins -= costs[i];
    }
    return answer;
}

void maximum_ice_cream_bars::Solution::test() {
    vector<int> costs {1, 3, 2, 4, 1};
    assert(maxIceCream(costs, 7) == 4);

    cout << "maxIceCream completed!" << endl;
}
