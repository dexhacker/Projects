//
// Created by dexhacker on 3/19/21.
//

#include "Solution.h"
#include <cassert>
#include <set>

int longest_consecutive_sequence::Solution::longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    set<int> nums_set;
    for (int i = 0; i < nums.size(); i++)
        nums_set.insert(nums[i]);

    auto it = nums_set.begin();
    if (nums_set.size() == 1) return 1;

    int previous_number = *it;
    it++;
    int max_length = 1;
    int current_length = 1;
    while (it != nums_set.end()) {
        if (previous_number + 1 == *it) {
            current_length++;
            if (max_length < current_length) max_length = current_length;
        } else {
            current_length = 1;
        }
        previous_number = *it;
        it++;
    }
    return max_length;
}

void longest_consecutive_sequence::Solution::test() {
    vector<int> test1 {100, 4, 200, 1, 3, 2};
    assert(longestConsecutive(test1) == 4);

    vector<int> test2 {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    assert(longestConsecutive(test2) == 9);

    vector<int> test3 {0};
    assert(longestConsecutive(test3) == 1);

    vector<int> test4 {-6, -1, -1, 9, -8, -6, -6, 4, 4, -3, -8, -1};
    assert(longestConsecutive(test4) == 1);

    std::cout << "longestConsecutive completed!" << std::endl;
}
