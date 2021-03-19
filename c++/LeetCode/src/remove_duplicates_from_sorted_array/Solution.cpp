//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

int remove_duplicates_from_sorted_array::Solution::removeDuplicates(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
        if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            nums.erase(nums.begin() + i + 1);
        else
            i++;
    }

    return nums.size();
}

void remove_duplicates_from_sorted_array::Solution::test() {
    vector<int> test1 {1, 1, 2};
    vector<int> answer1 {1, 2};
    assert(removeDuplicates(test1) == 2);
    assert(test1 == answer1);

    vector<int> test2 {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> answer2 {0, 1, 2, 3, 4};
    assert(removeDuplicates(test2) == 5);
    assert(test2 == answer2);

    std::cout << "removeDuplicates completed!" << std::endl;
}
