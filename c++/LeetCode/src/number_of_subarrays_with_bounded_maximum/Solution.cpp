//
// Created by dexhacker on 6/17/21.
//

#include "Solution.h"
#include <cassert>

int number_of_subarrays_with_bounded_maximum::Solution::numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    int result = 0, l = -1, r = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > right) l = i;
        if (nums[i] >= left) r = i;
        result += r - l;
    }
    return result;
}

void number_of_subarrays_with_bounded_maximum::Solution::test() {
    vector<int> test {2, 1, 4, 3};
    assert(numSubarrayBoundedMax(test, 2, 3) == 3);

    cout << "numSubarrayBoundedMax completed!" << endl;
}
