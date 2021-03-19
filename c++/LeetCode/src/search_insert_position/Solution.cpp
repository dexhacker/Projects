//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

int search_insert_position::Solution::searchInsert(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++)
        if (target == nums[i] || target < nums[i]) return i;
    return nums.size();
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

    std::cout << "searchInsert completed!" << std::endl;
}
