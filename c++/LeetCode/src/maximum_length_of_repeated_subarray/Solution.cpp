//
// Created by dexhacker on 7/8/21.
//

#include "Solution.h"
#include <cassert>

int maximum_length_of_repeated_subarray::Solution::findLength(vector<int> &nums1, vector<int> &nums2) {
    int answer = 0;
    vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
            if (nums1[i] == nums2[j]) {
                if (i == 0 or j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                answer = max(answer, dp[i][j]);
            }
        }
    }

    return answer;
}

void maximum_length_of_repeated_subarray::Solution::test() {
    vector<int> nums1 {1, 2, 3, 2, 1};
    vector<int> nums2 {3, 2, 1, 4, 7};
    assert(findLength(nums1, nums2) == 3);

    cout << "findLength completed!" << endl;
}
