//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <cassert>

int missing_number::Solution::missingNumber(vector<int> &nums) {
    int sum = nums.size();
    for (int i = 0; i < nums.size(); i++) sum += i -nums[i];
    return sum;
}

void missing_number::Solution::test() {
    vector<int> test1 {3, 0 ,1};
    assert(missingNumber(test1) == 2);

    vector<int> test2 {0 ,1};
    assert(missingNumber(test2) == 2);

    vector<int> test3 {9, 6, 4, 2, 3, 5, 7, 0, 1};
    assert(missingNumber(test3) == 8);

    vector<int> test4 {0};
    assert(missingNumber(test4) == 1);

    cout << "missingNumber completed!" << endl;
}
