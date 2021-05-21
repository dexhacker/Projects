//
// Created by dexhacker on 5/21/21.
//

#include "Solution.h"
#include <cassert>

int best_time_to_buy_and_sell_stock_with_transaction_fee::Solution::maxProfit(vector<int> &prices, int fee) {
    int max_profit = 0;
    int max_profit_with_stock = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
        int new_max_profit = max(max_profit, prices[i] - fee + max_profit_with_stock);
        max_profit_with_stock = max(max_profit_with_stock, -prices[i] + max_profit);
        max_profit = new_max_profit;
    }

    return max_profit;
}

void best_time_to_buy_and_sell_stock_with_transaction_fee::Solution::test() {
    vector<int> test1 {1, 3, 2, 8, 4, 9};
    assert(maxProfit(test1, 2) == 8);

    vector<int> test2 {1, 3, 7, 5, 10, 3};
    assert(maxProfit(test2, 3) == 6);

    cout << "maxProfit completed!" << endl;
}
