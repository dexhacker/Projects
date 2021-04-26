//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int find_minimum_in_rotated_sorted_array::Solution::findMin(vector<int> &nums) {
    int n = nums.size();
    if (nums[0] <= nums[n - 1]) return nums[0];

    int l = 1, r = n - 1;

    while (l < r) {
        int m = (l + r) / 2;
        if (nums[m] > nums[0])
            l = m + 1;
        else
            r = m;
    }
    return nums[l];
}

void find_minimum_in_rotated_sorted_array::Solution::test() {
    vector<int> test1 {3, 4, 5, 1, 2};
    assert(findMin(test1) == 1);

    vector<int> test2 {4, 5, 6, 7, 0, 1, 2};
    assert(findMin(test2) == 0);

    vector<int> test3 {11, 13, 15, 17};
    assert(findMin(test3) == 11);

    cout << "findMin completed!" << endl;
}
