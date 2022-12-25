//
// Created by dexhacker on 12/25/22.
//

#include "Solution.h"
#include <cassert>

vector<int> longest_subsequence_with_limited_sum::Solution::answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(nums.begin(), nums.end());
    vector<int> answer(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
        int sum = queries[i];
        for (int j = 0; j < nums.size(); j++) {
            sum -= nums[j];
            if (sum < 0) break;
            answer[i]++;
        }
    }
    return answer;
}

void longest_subsequence_with_limited_sum::Solution::test() {
    vector<int> nums {4, 5, 2, 1};
    vector<int> queries {3, 10, 21};
    vector<int> answer {2, 3, 4};
    auto result = answerQueries(nums, queries);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);
    cout << "answerQueries completed!" << endl;
}
