//
// Created by dexhacker on 6/29/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int max_consecutive_ones_iii::Solution::longestOnes(vector<int> &nums, int k) {
    queue<int> zero_indexes;
    int i = 0;
    int answer = 0;
    int current_size = 0;
    while (i < nums.size()) {
        if (nums[i] == 1) {
            ++current_size;
            answer = max(answer, current_size);
            ++i;
            continue;
        }

        if (zero_indexes.size() < k) {
            zero_indexes.push(i);
            ++current_size;
            answer = max(answer, current_size);
        } else {
            int index = i;
            if (!zero_indexes.empty()) index = zero_indexes.front();
            zero_indexes.pop();
            current_size = i - index;
            answer = max(answer, current_size);
            zero_indexes.push(i);
        }
        ++i;
    }

    return answer;
}

void max_consecutive_ones_iii::Solution::test() {
    vector<int> test {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    assert(longestOnes(test, 3) == 10);

    cout << "longestOnes completed!" << endl;
}
