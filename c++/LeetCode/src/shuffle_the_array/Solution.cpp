//
// Created by Farid on 06.02.2023.
//

#include "Solution.h"
#include <cassert>

vector<int> shuffle_the_array::Solution::shuffle(vector<int> &nums, int n) {
    vector<int> answer(nums.size());
    for (int i = 0; i < nums.size() / 2; i++) {
        answer[i * 2] = nums[i];
        answer[i * 2 + 1] = nums[i + nums.size() / 2];
    }
    return answer;
}

void shuffle_the_array::Solution::test() {
    vector<int> nums {2, 5, 1, 3, 4, 7};
    vector<int> answer {2, 3, 5, 4, 1, 7};
    auto result = shuffle(nums, 3);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "shuffle completed!" << endl;
}
