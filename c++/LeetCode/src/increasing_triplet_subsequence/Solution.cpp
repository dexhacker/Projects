//
// Created by dexhacker on 10/11/22.
//

#include "Solution.h"
#include <cassert>

bool increasing_triplet_subsequence::Solution::increasingTriplet(vector<int> &nums) {
    if (nums.size() < 3) return false;

    int min1 = 0, min2 = 0, mid1 = 0, i = 1;
    while (i < nums.size()) {
        if (nums[min1] < nums[i] && nums[i] < nums[mid1]) mid1 = i;
        if (nums[min1] < nums[mid1] && nums[mid1] < nums[i]) return true;

        if (nums[i] < nums[min2]) min2 = i;
        if (nums[min2] < nums[i]) {
            min1 = min2;
            mid1 = i;
        }

        i++;
    }

    return false;
}

void increasing_triplet_subsequence::Solution::test() {
    vector<int> test {1, 2, 3, 4, 5};
    assert(increasingTriplet(test) == true);

    cout << "increasingTriplet completed!" << endl;
}
