//
// Created by dexhacker on 12/23/22.
//

#include "Solution.h"
#include <cassert>

int best_time_to_buy_and_sell_stock_with_cooldown::Solution::maxProfit(vector<int> &prices) {
    vector<int> dp(prices.size(), 0);
    for (int i = 0; i < prices.size() - 1; i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            int result = prices[j] - prices[i];
            if (i > 1) result += dp[i - 2];
            if (j > 0) result = max(dp[j - 1], result);
            dp[j] = max(dp[j], result);
        }
    }
    return dp.back();
}

void best_time_to_buy_and_sell_stock_with_cooldown::Solution::test() {
    vector<int> prices {1, 2, 3, 0, 2};
    assert(maxProfit(prices) == 3);

    cout << "maxProfit completed!" << endl;
}
