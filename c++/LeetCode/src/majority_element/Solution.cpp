//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

int majority_element::Solution::majorityElement(vector<int> &nums) {
    int count = 1, major = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) {
            count++;
            major = nums[i];
        } else if (major == nums[i]) {
            count++;
        } else {
            count--;
        }
    }
    return major;
}

void majority_element::Solution::test() {
    vector<int> test1 {3, 2, 3};
    assert(majorityElement(test1) == 3);

    vector<int> test2 {2, 2, 1, 1, 1, 2, 2};
    assert(majorityElement(test2) == 2);

    cout << "majorityElement completed!" << endl;
}
