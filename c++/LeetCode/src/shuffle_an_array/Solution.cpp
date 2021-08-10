//
// Created by dexhacker on 7/20/21.
//

#include "Solution.h"
#include <cassert>

shuffle_an_array::Solution::Solution(vector<int> &nums) {
    numbers = nums;
}

vector<int> shuffle_an_array::Solution::reset() {
    return numbers;
}

vector<int> shuffle_an_array::Solution::shuffle() {
    vector<int> answer(numbers.size());
    vector<int> used(numbers.size(), false);
    for (int i = 0; i < numbers.size(); ++i) {
        int random_index = rand() % numbers.size();
        if (used[random_index]) {
            while(used[random_index]) {
                random_index = rand() % numbers.size();
            }

        }
        used[random_index] = true;
        answer[i] = numbers[random_index];
    }
    return answer;
}

void shuffle_an_array::Solution::test() {
    vector<int> test {1, 2, 3};
    auto obj = new Solution(test);
    obj->shuffle();
    assert(obj->reset() == test);
    obj->shuffle();

    cout << "shuffle completed!" << endl;
}
