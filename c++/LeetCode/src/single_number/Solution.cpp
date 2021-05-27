//
// Created by dexhacker on 5/22/21.
//

#include "Solution.h"
#include <cassert>

int single_number::Solution::singleNumber(vector<int> &nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

void single_number::Solution::test() {
    vector<int> test1 {2, 2, 1};
    assert(singleNumber(test1) == 1);

    vector<int> test2 {4, 1, 2, 1, 2};
    assert(singleNumber(test2) == 4);

    vector<int> test3 {1};
    assert(singleNumber(test3) == 1);

    cout << "singleNumber completed!" << endl;
}
