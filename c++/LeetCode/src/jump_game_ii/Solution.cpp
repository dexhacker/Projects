//
// Created by dexhacker on 9/20/22.
//

#include "Solution.h"
#include <cassert>

int jump_game_ii::Solution::jump(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++) {
        int jumps = dp[i] + 1;
        for (int j = i + 1; j <= i + nums[i]; j++) {
            if (j >=  dp.size()) break;

            if (dp[j] == 0) {
                dp[j] = jumps;
            } else {
                dp[j] = min(dp[j], jumps);
            }
        }
    }

    return dp.back();
}

void jump_game_ii::Solution::test() {
    vector<int> test1 {2, 3, 1, 1, 4};
    assert(jump(test1) == 2);

    cout << "jump completed!" << endl;
}
