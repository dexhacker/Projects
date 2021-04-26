//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int maximum_subarray::Solution::maxSubArray(vector<int> &nums) {
    int sum = 0, smax = INT32_MIN;
    for (int num : nums) {
        sum += num;
        smax = max(smax, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return smax;
}

void maximum_subarray::Solution::test() {
    vector<int> test1 {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(maxSubArray(test1) == 6);

    vector<int> test2 {1};
    assert(maxSubArray(test2) == 1);

    vector<int> test3 {5, 4, -1, 7, 8};
    assert(maxSubArray(test3) == 23);

    cout << "maxSubArray completed!" << endl;
}
