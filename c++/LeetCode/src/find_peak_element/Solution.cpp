//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int find_peak_element::Solution::findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void find_peak_element::Solution::test() {
    vector<int> test1 {1, 2, 3, 1};
    assert(findPeakElement(test1) == 2);

    vector<int> test2 {1, 2, 1, 3, 5, 6, 4};
    assert(findPeakElement(test2) == 5);

    vector<int> test3 {1, 2};
    assert(findPeakElement(test3) == 1);

    vector<int> test4 {1, 2, 1};
    assert(findPeakElement(test4) == 1);

    vector<int> test5 {1, 2, 3};
    assert(findPeakElement(test5) == 2);

    cout << "findPeakElement completed!" << endl;
}
