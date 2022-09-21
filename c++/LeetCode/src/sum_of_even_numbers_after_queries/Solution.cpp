//
// Created by dexhacker on 9/21/22.
//

#include "Solution.h"
#include <cassert>

vector<int> sum_of_even_numbers_after_queries::Solution::sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
    int sum = 0;
    vector<int> answer(queries.size());

    for (int i : nums) if (i % 2 == 0) sum += i;

    for (int i = 0; i < queries.size(); i++) {
        int val = queries[i][0];
        int index = queries[i][1];

        if (nums[index] % 2 == 0) sum -= nums[index];

        nums[index] += val;

        if (nums[index] % 2 == 0) sum += nums[index];

        answer[i] = sum;
    }

    return answer;
}

void sum_of_even_numbers_after_queries::Solution::test() {
    vector<int> test_nums1 {1, 2, 3, 4};
    vector<vector<int>> test_queries1 {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    vector<int> answer1 {8, 6, 2, 4};
    assert(sumEvenAfterQueries(test_nums1, test_queries1) == answer1);

    cout << "sumEvenAfterQueries completed!" << endl;
}
