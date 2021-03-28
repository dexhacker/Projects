//
// Created by dexhacker on 3/25/21.
//

#include "Solution.h"
#include <stack>
#include <cassert>

bool pattern132::Solution::find132pattern(vector<int> &nums) {
    int i = INT32_MIN;
    stack<int> filo;
    for (int l = nums.size() - 1; l >= 0; l--) {
        if (nums[l] < i) {
            return true;
        } else {
            while (!filo.empty() && filo.top() < nums[l]) {
                i = filo.top();
                filo.pop();
            }
            filo.push(nums[l]);
        }
    }
    return false;
}

void pattern132::Solution::test() {
    vector<int> test1 {1, 2, 3, 4};
    assert(find132pattern(test1) == false);

    vector<int> test2 {3, 1, 4, 2};
    assert(find132pattern(test2) == true);

    vector<int> test3 {-1, 3, 2, 0};
    assert(find132pattern(test3) == true);

    vector<int> test4 {1, 4, 0, -1, -2, -3, -1, -2};
    assert(find132pattern(test4) == true);

    std::cout << "find132pattern completed!" << std::endl;
}
