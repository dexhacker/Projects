//
// Created by dexhacker on 5/21/21.
//

#ifndef LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
#define LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H

#include <iostream>
#include <vector>

using namespace std;

namespace best_time_to_buy_and_sell_stock_with_transaction_fee {
    class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee);
        void test();
    };
}

#endif //LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
