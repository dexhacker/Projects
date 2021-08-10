//
// Created by dexhacker on 7/16/21.
//

#include "Solution.h"
#include <cassert>

int valid_triangle_number::Solution::triangleNumber(vector<int> &nums) {
    if (nums.size() < 3) return 0;

    int answer = 0;
    sort(nums.begin(), nums.end());

    int count = 0;
    int index = 0;
    vector<int> counts;
    for (int i = 0; i < 2000; ++i) {
        while (index < nums.size() and i > nums[index]) {
            ++count;
            ++index;
        }
        counts.push_back(count);
    }

    for (int i = 0; i < nums.size() - 2; ++i) {
        if (nums[i] == 0) continue;

        for (int j = i + 1; j < nums.size() - 1; ++j) {
            answer += counts[nums[i] + nums[j]] - (j + 1);
        }
    }

    return answer;
}

void valid_triangle_number::Solution::test() {
    vector<int> test {2, 2, 3, 4};
    assert(triangleNumber(test) == 3);

    cout << "triangleNumber completed!" << endl;
}
