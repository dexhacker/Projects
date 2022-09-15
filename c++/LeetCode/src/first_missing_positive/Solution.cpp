//
// Created by dexhacker on 9/15/22.
//

#include "Solution.h"
#include <cassert>

int first_missing_positive::Solution::firstMissingPositive(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == i + 1) continue;

        if (nums[i] <= 0 || nums[i] > nums.size()) {
            nums[i] = 0;
            continue;
        }

        int number = nums[i];
        nums[i] = 0;
        while (true) {
            if (number <= 0 || number > nums.size() || nums[number - 1] == number) break;

            int tmp = nums[number - 1];
            nums[number - 1] = number;
            number = tmp;
        }
    }

    for (int i = 0; i < nums.size(); i++) if (nums[i] == 0) return i + 1;

    return nums.size() + 1;
}

void first_missing_positive::Solution::test() {
    vector<int> test1 {1, 2, 0};
    assert(firstMissingPositive(test1) == 3);

    vector<int> test2 {3, 4, -1, 1};
    assert(firstMissingPositive(test2) == 2);

    vector<int> test3 {7, 8, 9, 11, 12};
    assert(firstMissingPositive(test3) == 1);

    cout << "firstMissingPositive completed!" << endl;
}
