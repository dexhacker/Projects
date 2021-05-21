//
// Created by dexhacker on 5/20/21.
//

#include "Solution.h"
#include <cassert>

int best_time_to_buy_and_sell_stock_ii::Solution::maxProfit(vector<int> &prices) {
    int max_profit = 0;
    int max_profit_with_stock = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
        int new_max_profit = max(max_profit, prices[i] + max_profit_with_stock);
        max_profit_with_stock = max(max_profit_with_stock, -prices[i] + max_profit);
        max_profit = new_max_profit;
    }

    return max_profit;
}

void best_time_to_buy_and_sell_stock_ii::Solution::test() {
    vector<int> test1 {7, 1, 5, 3, 6, 4};
    assert(maxProfit(test1) == 7);

    vector<int> test2 {1, 2, 3, 4, 5};
    assert(maxProfit(test2) == 4);

    vector<int> test3 {7, 6, 4, 3, 1};
    assert(maxProfit(test3) == 0);

    cout << "maxProfit completed!" << endl;
}
