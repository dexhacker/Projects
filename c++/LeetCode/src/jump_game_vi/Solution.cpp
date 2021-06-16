//
// Created by dexhacker on 6/9/21.
//

#include "Solution.h"
#include <deque>
#include <cassert>

int jump_game_vi::Solution::maxResult(vector<int> &nums, int k) {
    int curr = 0;
    deque<int> dq;

    for(int i = nums.size() - 1; i >= 0; i--) {
        curr = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);

        while(!dq.empty() && curr > nums[dq.back()]) dq.pop_back();
        dq.push_back(i);

        if(dq.front() >= i + k) dq.pop_front();
        nums[i] = curr;
    }
    return curr;
}

void jump_game_vi::Solution::test() {
    vector<int> test {1, -1, -2, 4, -7, 3};
    assert(maxResult(test, 2) == 7);

    cout << "canJump completed!" << endl;
}
