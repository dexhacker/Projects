//
// Created by dexhacker on 4/30/21.
//

#include "Solution.h"
#include <cassert>

int coin_change::Solution::coinChange(vector<int> &coins, int amount) {
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

void coin_change::Solution::test() {
    vector<int> test1 {1, 2, 5};
    assert(coinChange(test1, 11) == 3);

    vector<int> test2 {2};
    assert(coinChange(test2, 3) == -1);

    vector<int> test3 {1};
    assert(coinChange(test3, 0) == 0);

    vector<int> test4 {1};
    assert(coinChange(test4, 1) == 1);

    vector<int> test5 {1};
    assert(coinChange(test5, 2) == 2);

    vector<int> test6 {186, 419, 83, 408};
    assert(coinChange(test6, 6249) == 20);

    vector<int> test7 {3, 7, 405, 436};
    assert(coinChange(test7, 8839) == 25);

    cout << "coinChange completed!" << endl;
}
