//
// Created by dexhacker on 7/2/21.
//

#include "Solution.h"
#include <cassert>

vector<int> find_k_closest_elements::Solution::findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> dp(arr.size() - k + 1, -1);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += abs(arr[i] - x);
    }

    dp[0] = sum;
    for (int i = k; i < arr.size(); i++) {
        sum = sum - abs(arr[i - k] - x) + abs(arr[i] - x);
        dp[i - k + 1] = sum;
    }

    int min_sum_index = 0;
    for (int i = 1; i < dp.size(); i++) {
        if (dp[i] < dp[min_sum_index]) min_sum_index = i;
    }

    vector<int> answer;
    for (int i = 0; i < k && i + min_sum_index < arr.size(); i++) {
        answer.push_back(arr[min_sum_index + i]);
    }

    return answer;
}

void find_k_closest_elements::Solution::test() {
    vector<int> test {1, 2, 3, 4, 5};
    vector<int> answer {1, 2, 3, 4};
    assert(findClosestElements(test, 4, 3) == answer);

    cout << "findClosestElements completed!" << endl;
}
