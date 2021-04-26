//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int best_time_to_buy_and_sell_stock::Solution::maxProfit(vector<int> &prices) {
    int min = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (min > prices[i]) min = prices[i];
        if (min < prices[i] && profit < prices[i] - min) profit = prices[i] - min;
    }
    return profit;
}

void best_time_to_buy_and_sell_stock::Solution::test() {
    vector<int> test1 {7, 1, 5, 3, 6, 4};
    assert(maxProfit(test1) == 5);

    vector<int> test2 {7, 6, 4, 3, 1};
    assert(maxProfit(test2) == 0);

    vector<int> test3 {7, 1, 5, 3, 6, 4, 0};
    assert(maxProfit(test3) == 5);

    vector<int> test4 {1, 2};
    assert(maxProfit(test4) == 1);

    cout << "maxProfit completed!" << endl;
}
