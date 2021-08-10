//
// Created by dexhacker on 7/22/21.
//

#include "Solution.h"
#include <cassert>

int partition_array_into_disjoint_intervals::Solution::partitionDisjoint(vector<int> &nums) {
    vector<int> minimums(nums.size(), false);

    minimums[nums.size() - 1] = nums[nums.size() - 1];
    int minimum = minimums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] < minimum) minimum = nums[i];
        minimums[i] = minimum;
    }

    int maximum = INT32_MIN;
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (maximum < nums[i]) maximum = nums[i];
        if (maximum <= minimums[i + 1]) return i + 1;
    }

    return nums.size();
}

void partition_array_into_disjoint_intervals::Solution::test() {
    vector<int> test {1, 1, 1, 0, 6, 12};
    assert(partitionDisjoint(test) == 4);

    cout << "partitionDisjoint completed!" << endl;
}
