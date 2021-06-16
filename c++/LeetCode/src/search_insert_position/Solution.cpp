//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

int search_insert_position::Solution::searchInsert(vector<int> &nums, int target) {
    int l = 0, r = (int)nums.size() - 1;
    int greater = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] > target) {
            greater = m;
            r = m - 1;
        } else if (nums[m] < target) {
            greater = m + 1;
            l = m + 1;
        } else {
            return m;
        }
    }
    return greater;
}

void search_insert_position::Solution::test() {
    vector<int> test1 {1, 3, 5, 6};
    assert(searchInsert(test1, 5) == 2);

    vector<int> test2 {1, 3, 5, 6};
    assert(searchInsert(test2, 2) == 1);

    vector<int> test3 {1, 3, 5, 6};
    assert(searchInsert(test3, 7) == 4);

    vector<int> test4 {1, 3, 5, 6};
    assert(searchInsert(test4, 0) == 0);

    vector<int> test5 {1};
    assert(searchInsert(test4, 0) == 0);

    cout << "searchInsert completed!" << endl;
}
