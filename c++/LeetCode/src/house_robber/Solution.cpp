//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <cassert>

int house_robber::Solution::rob(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        int ans1 = nums[i], ans2 = nums[i];
        if (i - 2 >= 0) ans1 = nums[i] + nums[i - 2];
        if (i - 3 >= 0) ans2 = nums[i] + nums[i - 3];
        nums[i] = max(ans1, ans2);
        answer = max(answer, nums[i]);
    }
    return answer;
}

void house_robber::Solution::test() {
    vector<int> test1 {1, 2, 3, 1};
    assert(rob(test1) == 4);

    vector<int> test2 {2, 7, 9, 3, 1};
    assert(rob(test2) == 12);

    cout << "rob completed!" << endl;
}
