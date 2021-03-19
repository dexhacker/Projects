//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>
#include <set>

int third_maximum_number::Solution::thirdMax(vector<int> &nums) {
    set<int> a(nums.begin(), nums.end());
    set<int>::iterator it = a.end();
    if (a.size() > 2) {
        it--; it--; it--;
    } else {
        it--;
    }
    return *it;
}

void third_maximum_number::Solution::test() {
    vector<int> test1 {3, 2, 1};
    assert(thirdMax(test1) == 1);

    vector<int> test2 {1, 2};
    assert(thirdMax(test2) == 2);

    vector<int> test3 {2, 2, 3, 1};
    assert(thirdMax(test3) == 1);

    cout << "thirdMax completed!" << endl;
}
