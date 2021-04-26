//
// Created by dexhacker on 4/26/21.
//

#include "Solution.h"
#include <cassert>

int burst_balloons::Solution::maxCoins(vector<int>& nums, int l, int r) {
    if (cache[l][r] != -1) {
        return cache[l][r];
    }
    int max_coins = 0;
    for (int i = l; i <= r; i++) {
        int coins = nums[i];
        if (l > 0) coins *= nums[l - 1];
        if (r < nums.size() - 1) coins *= nums[r + 1];
        if (i > l) coins += maxCoins(nums, l, i - 1);
        if (i < r) coins += maxCoins(nums, i + 1, r);
        max_coins = max(max_coins, coins);
    }
    cache[l][r] = max_coins;
    return max_coins;
}

int burst_balloons::Solution::maxCoins(vector<int> &nums) {
    cache = vector<vector<int>> (505, vector<int>(505, -1));
    if (nums.size() == 0) return 0;

    return maxCoins(nums, 0, nums.size() - 1);
}

void burst_balloons::Solution::test() {
    vector<int> test1 {3, 1, 5, 8};
    assert(maxCoins(test1) == 167);

    vector<int> test2 {1, 5};
    assert(maxCoins(test2) == 10);

    cout << "maxCoins completed!" << endl;
}
