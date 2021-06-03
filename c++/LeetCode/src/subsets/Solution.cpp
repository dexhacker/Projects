//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <cassert>

void subsets::Solution::push_nums(vector<int> nums) {
    int i = 0;
    if (!nums.empty()) i = hm[nums.back()] + 1;

    for (; i < numbers.size(); i++) {
        vector<int> tmp(nums);
        tmp.push_back(numbers[i]);
        answer.push_back(tmp);
        push_nums(tmp);
    }
}

vector<vector<int>> subsets::Solution::subsets(vector<int> &nums) {
    answer.push_back({});
    numbers = nums;

    for (int i = 0; i < numbers.size(); i++) hm[numbers[i]] = i;

    push_nums(answer[0]);

    return answer;
}

void subsets::Solution::test() {
    vector<int> test {1, 2, 3};
    vector<vector<int>> answer {{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}};
    assert(subsets(test) == answer);

    cout << "subsets completed!" << endl;
}
