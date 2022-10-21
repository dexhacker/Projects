//
// Created by dexhacker on 10/21/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool contains_duplicate_ii::Solution::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.count(nums[i]) > 0 && i - m[nums[i]] <= k) return true;

        m[nums[i]] = i;
    }

    return false;
}

void contains_duplicate_ii::Solution::test() {
    vector<int> test {1, 2, 3, 1};
    assert(containsNearbyDuplicate(test, 3) == true);

    cout << "containsNearbyDuplicate completed!" << endl;
}
