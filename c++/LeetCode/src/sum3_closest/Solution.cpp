//
// Created by dexhacker on 6/22/21.
//

#include "Solution.h"
#include <cassert>

int sum3_closest::Solution::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int answer = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(target - answer) > abs(target - sum)) answer = sum;

            if (sum > target) {
                --r;
            } else {
                ++l;
            }
        }
    }
    return answer;
}

void sum3_closest::Solution::test() {
    vector<int> test {-1, 2, 1, -4};
    assert(threeSumClosest(test, 1) == 2);

    cout << "threeSumClosest completed!" << endl;
}
