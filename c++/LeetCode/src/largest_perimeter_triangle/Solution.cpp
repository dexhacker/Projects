//
// Created by dexhacker on 10/12/22.
//

#include "Solution.h"
#include <cassert>

int largest_perimeter_triangle::Solution::largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    for (int i = nums.size() - 3; i >= 0; i--) {
        int a = nums[i];
        int b = nums[i + 1];
        int c = nums[i + 2];
        if (c >= a + b) continue;

        return a + b + c;
    }

    return 0;
}

void largest_perimeter_triangle::Solution::test() {
    vector<int> test {2, 1, 2};
    assert(largestPerimeter(test) == 5);

    cout << "largestPerimeter completed!" << endl;
}
