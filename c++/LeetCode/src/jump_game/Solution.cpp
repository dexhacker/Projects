//
// Created by dexhacker on 5/20/21.
//

#include "Solution.h"
#include <cassert>

bool jump_game::Solution::canJump(vector<int> &nums) {
    int smallest_reachable = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
        if (nums[i] + i >= smallest_reachable)
            smallest_reachable = i;
    return smallest_reachable == 0;
}

void jump_game::Solution::test() {
    vector<int> test1 {2, 3, 1, 1, 4};
    assert(canJump(test1) == true);

    vector<int> test2 {3, 2, 1, 0, 4};
    assert(canJump(test2) == false);

    cout << "canJump completed!" << endl;
}
