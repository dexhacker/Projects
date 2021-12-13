//
// Created by Фарид Абдугалыев on 13.12.2021.
//

#include "Solution.h"
#include <cassert>

int remove_element::Solution::removeElement(vector<int> &nums, int val) {
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == val) {
            nums[i] = nums.back();
            nums.pop_back();
        }
    }
    return nums.size();
}

void remove_element::Solution::test() {
    vector<int> test1 = {3, 2, 2, 3};
    vector<int> test2 = {0, 1, 2, 2, 3, 0, 4, 2};

    assert(removeElement(test1, 3) == 2);
    assert(removeElement(test2, 2) == 5);

    cout << "removeElement completed!" << endl;
}
