//
// Created by dexhacker on 3/18/21.
//

#include "Solution.h"
#include <cassert>

int count_number_of_nice_subarrays::Solution::numberOfSubarrays(vector<int> &nums, int k) {
    int l = 0, r = 0;
    int odd_count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 1)
            odd_count++;

        if (odd_count == k) {
            r = i + 1;
            break;
        }
    }
    if (odd_count < k) return 0;

    int answer = 0;
    int l_count = 0, r_count = 0;
    while (true) {
        if (nums[l] % 2 == 1 && (r == nums.size() || nums[r] % 2 == 1)) {
            answer += (l_count + 1) * (r_count + 1);
            if (r >= nums.size()) break;
            l_count = 0;
            r_count = 0;
            l++; r++;
            continue;
        }

        if (nums[l] % 2 == 0) {
            l++;
            l_count++;
        }

        if (r < nums.size() && nums[r] % 2 == 0) {
            r++;
            r_count++;
        }
    }
    return answer;
}

void count_number_of_nice_subarrays::Solution::test() {
    vector<int> test1 {1, 1, 2, 1, 1};
    assert(numberOfSubarrays(test1, 3) == 2);

    vector<int> test2 {2, 4, 6};
    assert(numberOfSubarrays(test2, 1) == 0);

    vector<int> test3 {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    assert(numberOfSubarrays(test3, 2) == 16);

    vector<int> test4 {91473, 45388, 24720, 35841, 29648, 77363, 86290, 58032, 53752, 87188, 34428, 85343, 19801, 73201};
    assert(numberOfSubarrays(test4, 4) == 6);

    cout << "numberOfSubarrays completed!" << endl;
}
